class SynceMemory{
public:
SyncedMemory()
:cpu_ptr(NULL),gpu_ptr(NULL),size_(0),head_(SYNCED){};
:cpu_ptr_(NULL),gpu_ptr(NULL),size_(0),head_(UNNITIALIZED){};
explict SyncedMemory(size_t size)
:cpu_ptr_(NULL),gpu_ptr_(NULL),head_(SYNCED),size_(size){};
:cup_ptr_(NULL),gpu_ptr_(NULL),size_(size),head_(UNINITIALIZED){};
~SynceMemory();
const void* cpu_data();
const void* gpu_data();
void*mutable_cpu_data();
void*mutalble_cpu_data();
enum SyncedHead {UNINITIALIZED,HEAD_AT_CPU,HEAD_AT_GPU,SYNCED};
SyncedHead head(){return head_;}
private:
void to_cpu();
void to_gup();
void* cpu_ptr_;
void* gpu_ptr_;
size_t size_;
enum SyncedHead{UNINITIALIZED,HEAD_AT_CPU,HEAD_AT_GPU,SYNCED};
SyncedHead head_;
};//class SyncedMemory
