#include <iostream>
#include <stdio.h>
#include <sys/stat.h>
#include <fstream>
#include <sstream>
#include <string.h>
#include <map>
#include <cassert>
#include <functional>
#include <set>
#include <unordered_map>
#include <vector>

#include "../src/shape.h"
#include "../src/circle.h"
#include "../src/triangle.h"
#include "../src/rectangle.h"
#include "../src/sort.h"

using namespace::std;

/*
argument 1 : input file path.

argument 2 : output file path.

argument 3 : method (area or perimeter).

argument 4 : order (inc or dec).
*/

template<typename Key_t>
void switchFunction(const Key_t& key,
    const vector<pair<Key_t, function<void()>>>& pairs,
    const function<void()>& def)
{
    unordered_map<Key_t, function<void()>> dict;
    for (const auto& entry : pairs)
    {
        dict.insert(entry);
    }

    assert(dict.size() == pairs.size());

    const auto it = dict.find(key);

    if (it != dict.end())
    {
        it->second();
    }
    else
    {
        def();
    }
}

template<typename F, typename... Args>
function<void()> defer(F f, Args ... args)
{
    return [f, args...]()
    {
        f(args...);
    };
}

vector<Shape*> parse_file(string filepath)
{
    Shape* myarray[] = {};
    vector<Shape*> myvector(myarray, myarray);

    ifstream myfile;
    myfile.open (filepath);

    //read the file as pure string
    stringstream strStream;
    strStream << myfile.rdbuf();     //read the file
    string myFile = strStream.str(); //str holds the content of the file

    string function;
    string number;
    array<double,10> arg;
    int arg_num = 0;
    int array_num = 0;
    int p = 0;

    for (string::size_type i = 0; i < myFile.size(); ++i)
    {  
        if (myFile[i]==' ')
        {
            function = myFile.substr(p, i-p); 
            p = i + 1;
        }
        
        else if (myFile[i]=='(')
        {
            p = i + 1;
        }

        else if (myFile[i]=='\n')
        {
            p = i + 1;
        }

        else if (myFile[i]==',')
        {
            string number = myFile.substr(p, i-p);
            arg[arg_num] = stod(number);
            number.clear();
            arg_num += 1;
            p = i + 1;
        }
        else if (myFile[i]==')')
        {
            string number = myFile.substr(p, i-p);
            arg[arg_num] = stod(number);
            number.clear();
            arg_num = 0;
            p = i + 1;

            /*
            switchFunction(function, {
            {"Circle",    defer(put_in, myarray, array_num, new Circle(arg[0]))},
            {"Rectangle", defer([](){})},
            {"Triangle",  defer([](){})}},
            defer([](){throw string("No such function.");}));
            */
            
            if (function=="Circle")
            { 
                myvector.push_back(new Circle(arg[0]));
            } 
            else if (function=="Rectangle")
            {
                myvector.push_back(new Rectangle(arg[0], arg[1]));
            } 
            else if (function=="Triangle") 
            {
                myvector.push_back(new Triangle(arg[0], arg[1], arg[2], arg[3], arg[4], arg[5]));
            }
                                                                             
            arg.fill(0);
            array_num += 1;
        }

    }
    myfile.close();

    return myvector;
}

void write_file(vector<double> v, string destination)
{
    ofstream outfile;
    outfile.open(destination);

    outfile << "[";
    for (vector<double>::iterator it = v.begin() ; it != v.end(); ++it)
    {
        outfile << *it;
        if (it != v.end()-1) outfile << ",";
    }
    outfile << "]";
    outfile.close();
}
     
int  main(int argc, char *argv[])
{
    //check 5 argc 
    if(argc < 5){
        fprintf(stderr, "usage: %s <function>\n", argv[0]);
        return 0;
    }

    string inputfile  = argv[1];
    string outputfile = argv[2];
    string method     = argv[3];
    string order      = argv[4];
    
    //check file exist
    try
    {
        ifstream test(argv[1]);
        test.exceptions(ifstream::failbit);
    }
    catch (ios_base::failure& fail)
    {
        fprintf(stderr, "file: %s don't exist\n", argv[1]);
        return 0;
    }

    vector<Shape*> myvector;

    //read file
    try
    {
        myvector = parse_file(inputfile);
    }
    catch (const string& e)
    {
        cout<<"Caught exception:"<<e<<endl;
        return 0;
    }

    int op_id;

    if (method=="area")
    {
    	op_id = 10;
    } 
    else if (method=="perimeter")
    {
    	op_id = 20;
    }
    else if (method=="compactness")
    {
    	op_id = 30;
    }
    else
    {
        throw string("No such method.");
    }

    if (order=="inc")
    {
    	op_id += 1;
    }
    else if (order=="dec")
    {
    	op_id += 2;
    }
    else
    {
        throw string("No such order.");
    }

    Sort *s = new Sort(&myvector);
    vector<double> sortedData;

    //sort
    switch(op_id)
    {
        case 11:
            s->sortArea([](Shape *a, Shape *b){return a->area() < b->area();}); 
            for (vector<Shape*>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
            {   
                sortedData.push_back((*it)->area());
            }
            break;

        case 12:
            s->sortArea([](Shape *a, Shape *b){return a->area() > b->area();});
            for (vector<Shape*>::iterator it = myvector.begin() ; it != myvector.end(); ++it) 
            {
                sortedData.push_back((*it)->area());
            }
            break;   

        case 21:
            s->sortPerimeter([](Shape *a, Shape *b){return a->perimeter() < b->perimeter();});
            for (vector<Shape*>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
            {
                sortedData.push_back((*it)->perimeter());
            }
            break;

        case 22:
            s->sortPerimeter([](Shape *a, Shape *b){return a->perimeter() > b->perimeter();});
            for (vector<Shape*>::iterator it = myvector.begin() ; it != myvector.end(); ++it) 
            {
                sortedData.push_back((*it)->perimeter());
            }
            break;

        case 31:
            s->sortCompactness([](Shape *a, Shape *b){return a->compactness() < b->compactness();});
            for (vector<Shape*>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
            {
                sortedData.push_back((*it)->compactness());
            }
            break;

        case 32:
            s->sortCompactness([](Shape *a, Shape *b){return a->compactness() > b->compactness();});
            for (vector<Shape*>::iterator it = myvector.begin() ; it != myvector.end(); ++it) 
            {
                sortedData.push_back((*it)->compactness());
            }
            break;
    }

    //write file
    try
    {
        write_file(sortedData, outputfile);
    }
    catch (const string& e)
    {
        cout<<"Caught exception:"<<e<<endl;
        return 0;
    }
}
