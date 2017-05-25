//
//  blob.hpp
//  Caffe
//
//  Created by woke on 2017/5/25.
//
//

#ifndef blob_hpp
#define blob_hpp

#include <stdio.h>

#endif /* blob_hpp */


namespace caffeine{
    template<typename Dtype>
    class Blob{
    public:
        Blob()
        :num_(0),channels_(0),height_(0),width_(0),count_(0),data_(),
        diff_(){};
        Explicit Blob(const int num, const int channels, const int height, const int width){
            Reshape(num,channels,height,width);
        }
    };
    ~Blob(){};
    void Reshape(const int num, const int channels, const int height,const int width);
    
    inline int num(){
        return num_;
    }
    
    inline int channels(){return channels_;}
    inline int height(){return height_;}
    inline int width(){return width_;}
    
    const Dtype*cpu_data();
    const Dtype*gpu_data();
    const Dtype*cpu_diff();
    const Dtype*gpu_diff();
    Dtype*mutable_cpu_data();
    Dtype*mutable_gpu_data();
    Dtype*mutable_cpu_diff();
    Dtype*mutalble_gpu_diff();
private:
    void check_data();
    void check_diff();
    shared__ptr<SynceMemory> data_;
    shared__ptr<SynceMemory> diff_;
    int num_;
    int channels_;
    int height_;
    int width_;
    int count_;
};
}
#endif
