!(condition)?nullout:std:cout
define CHECK(condition)\
LOG_IF(condition)<<"Check failed:"#condition""

ifndef NDEBUG

define DCHECK(condition) CHECK(condition)

else

define DCHECK(condition)

endif //NDEBUG

define CUDA_CHECK(condtion)\
    CUDA_LOG_IF(condition)<<"Check failed:"condition""
    
    //TODO(Yangqing):make a better logging scheme
    define CUDA_LOG_IF(condition)\
    ((condition) !=cudaSuccess)?nullout:std::cout
    define CUDA_CHECK(condition)\
    LOG_IF(condition)<<"Check failed:"#condition""
    
    CUDA_LOG_IF(condition)<<"Check failed:"#condition""
    
    ifndef NDEBUG
    define CUDA_CHECK(condition) CUDA_CHECK(condtion)
    else
    
    define CUDA_DCHECK(condition)
    endif
    
    endif // CAFFEINE_COMMON_HPP
    
