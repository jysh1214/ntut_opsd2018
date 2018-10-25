#include <gtest/gtest.h>
#include "../src/node.h"
#include "../src/folder.h"
#include "../src/file.h"
#include "./ut_fs.h"

int main(int argc, char ** argv)
{
    testing::InitGoogleTest( &argc , argv );
    return RUN_ALL_TESTS();
}
