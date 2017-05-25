//
//  blob.cpp
//  Caffe
//
//  Created by woke on 2017/5/25.
//
//

#include "blob.hpp"


namespace caffeine {
    template <typename Dtype>
}

void Blob<Dtype>::Reshape(const int num, const int channels, const int height,const int width){
    num_ = num;
    channels_ = channels;
    height_ =height;
    width_ = width;
    count_ = num_* channels_* height_ *width;
    data_.reset(SyncedMemory(count_*sizeof(Dtype)));
    diff.reset(SyncedMemory(count_*sizeof(Dtype)));
    data_.reset(new SyncedMemory(count_* sizeof(Dtype)));
    diff_.reset(new SyncedMemory(count_*sizeof(Dtype)));
}

template<typename Dtype>
Dtype*Blob<Dtype>::mutable_cpu_data(){
    check_data();
    return data_->mutable_cpu_data();
}

tempalte<typename Dtype>
Dtype*Blob<Dtype>::mutable_gpu_data(){
    check_data();
    return data_->mutable_gpu_data();
    
}

template<typename Dtype>
Dtype*Blob<Dtype>::mutable_cpu_diff(){
    check_diff();
    return diff_->mutable_cpu_data();
}

template<typename Dtype>
Dtype*Blob<Dtype>::mutable_gpu_diff(){
    check_dirr();
    return diff_->mutable_gpu_data();
}

template<typename Dtype>
void Blob<Dtype>::update(){
    
}  //namespace caffeine
