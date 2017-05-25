//
//  base.h
//  Caffe
//
//  Created by woke on 2017/5/25.
//
//

#ifndef base_h
#define base_h


#endif /* base_h */


using std::vector;
namespace caffeine{
    template <typename Dtype>
    class Layer{
    public:
        explicit Layer(const LayerParameter& param)
        : initialized_(false),layer_param_(param){};
        ~Layer();
        virtual void SetUp(vector<const Blob<Dtype>*>& bottom,)
        vector<Blob<Dtype>*>* top) =0;
        
        virtual void Forward(vector<const Blob<Dtype*>& bottom,)
        vector<Blob<Dtype>*>*top) = 0;
        virtual void Predict(vetor<const Blob<Dtype>*>& bottom,)
        vector<Blob<Dtype*>* top) =0;
        virtual void Backward(vector<const Blob<Dtype>*>& bottom,)
        vector<Blob<Dtype>*>*top,bool propagate_down) = 0;
    protected:
        bool initialized_;
        //The protobuf that stores the layer parameters
        LayerParameter layer_param;
        //The vector that stores the parameters as a set of blobs.
        vector<Blob<Dtype>>blobs;
    };  //class Layer
}
//namespace caffeine

endif //CAFFEINE_BASE_H_
