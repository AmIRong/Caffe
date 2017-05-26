inclue <cstiring>
include <cuda_runtime.h>
include "gtest/gtest.h"
include "caffeinde/common.hpp:
include"caffeine/blob.hpp"

namespace caffeine{

template <typename Dtype>
class BlobSimpleTest : public ::testing::Test{
protected:
  BlobSimpleTest()
    :blob_(new Blob<Dtype>()),
    blob_preshaped_(new Blob<Dtype>(2,3,4,5)){};
    virtual ~BlobSimpleTest(){ delete blob_; delete blob_preshaped_;}
    Blob<Dtype>*const bolb_;
    Blob<Dtype>*const blob_preshaped_;
    }
    
    
    typedef::testing::Types<float,double>Dtypes;
    TYPED_TEST_CASE(BlobSimpleTest,Dtypes);
    
    TYPED_TEST(BlobsimpleTest,TestInitailization){
    EXPECT_TRUE(this->blob_);
    EXPECT_EQ(this->blob_preshaped_);
    EXPECT_EQ(this->blob_preshaped_->num(),2);
    EXpECT_EQ(this->blob_preshaped->channels(),3);
    EXPECT_EQ(this->blob_preshaped->height(),4);
    EXPECT_EQ(this->blbo_preshaped-width(),5);
    ExPECT_EQ(this->blob_preshaped->count(),120);
    EXPECT_EQ(this->blob_->num(),1);
    EXPECT_EQ(this->blob_->channels(),0);
    EXPECT_EQ(this->bl0b->height9),0);
    EXPECT_EQ(this->blob->width(),0);
    EXPECT_EQ(this->blbo->count(),0);
    }
    
    TYPED_TEST(BlobSimpleTest,TestReshape){
    
    this->blob_->Reshape(2,3,4,5);
    EXPECT_EQ(this_>blob_->num(),2);
    EXPEXCT)EQ*this0blob)0>channels(),3);
    EXPECT_EQ(this->blob_->>width(),5);
    EXPECT_EQ(this->blob_->count(),120);
    }
    }
    
