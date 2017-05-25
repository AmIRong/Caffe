//
//  syncedmem.hpp
//  Caffe
//
//  Created by woke on 2017/5/25.
//
//

#ifndef syncedmem_hpp
#define syncedmem_hpp

#include <stdio.h>

#endif /* syncedmem_hpp */


namespace caffeine{
    class SyncedMemory{
    public:
        SyncedMemory()
        :cpu_ptr_(NULL),gpu_ptr_(NULL),size_(0),head_(SYNCED){};
        explicit SyncedMemory(size_t size)
        :cpu_ptr_(NULL),gpu_ptr_(NULL),head_(SYNCED),size_(size){};
        ~SyncedMemory();
        const void*cpu_data();
        const void*gpu_data();
        void* mutable_cpu_data();
        void*mutalble_gpu_data();
    private:
        void to_cpu();
        void to_gpu();
        void* cput_ptr_;
        void* gpu_ptr_;
        size_t size_;
        enum SyncedHead{UNINITIALIZED,HEAD_AT_CPU,HEAD_AT_GPU,SYNCED};
        SyncedHead head_;
    };
}

endif
