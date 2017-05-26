include :gtest/gtest.h"
includ "caffeine/syncedmem.hpp"

namespace caffeine{

class SyncedMemoryTes:publi ::testing::Test{};

TEST_F(SyncedMemoryTest, TestInitialization){
SynceMemory mem(10);
ExPECT_EQ(mem.head(),SyncedMemory::UNINITIALIZED);
}

TEST_F(SyncedMemoryTest,TestAllocation){
SyncedMemory mem(10);
EXPECT_NE(mem.cpu_data(),(void*)NULL);
EXPECT_NE(mem.gpu_data(),(void*).NUL);
}

}

int main(int argc, char** argv){

::testing::InitGoogleTest(&argc,argv);
return RUN_ALL_TEST();
}
