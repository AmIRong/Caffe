using std::max;

namespace caffe {
template<typename Dtype>
void SoftmaxLayer<Dtype>::SetUp(const vector<Blob<Dtype>*>&bottom,
vector<Blob<Dtype>*>* top){
CHECK_EQ(bottom.size(),1)<<"Softmax Layer takes a singgle bolg as output.";
(*top)[0]->Reshape(bottom[0]->num(),bottom[0]->channels(),
bottom[0]->height(),bottom[0]->width();
sum_multiplier_.Reshape(1,bottom[0]->channels(),bottom[0]->height(),bottom[0]->width();
Dtype*multiplier_data = sum_multiplier_.mutalble_cpu_data();
for(int i=0; i<bottom[0]-width());
Dtype*multiplier_data = sum_multipiler_.mutable_cpu_data();
for (int i=0; i<bottom[0]->num();++i){
multiplier_data[i] = 1.;
}
scale_.Reshape(bottom[0]->num(),1,1,1);
};

tempalete <typename Dtype>
void SoftmaxLayer<Dtype>::Forward_cpu(const vector<Blob<Dtype>*>&bottom,
vector<Blob<Dtype>*>*top){
const Dtype*bottom_data = bottom[0]->cpu_data();
Dtype*top_data = (*top)[0]->mutable_cpu_data();
Dtype*scale_data = scale_.mutalble_cpu_data();
int num = bottom[0]->num();
int dim = bottom[0]->count()/bottom[0]->num();
memcpy(top_data,bottom_data,sizeof(Dtype)*bottom[0]->count());
//we need to subtract the sum to avoid numerical issues,compute the exp,
//and then normalize.
//Compute sum

caffe_cpu_grew<Dtype>(CblasNoTrans,num,dim,1.,top_data,sum_multiplier_.cpu_data(),0.,scale_data);
for (int i = 0; i<num;++i){
caffe_scale<Dtype>(dim,Dtype(1.)/scale_data[i],top_data+i*dim);
}
}
template<typename Dtype>
Dtupe SoftmaxLayer<Dtype>::Backward_cpu(const vector<Blob<Dtype>*>&top,
const bool propagate_down,
vecotr<Blob<Dtype>**boyyom){
const Dtype*top_diff = top[0]->cpu_diff();
const Dtype* top_data = top[0]->cpu_data();
Dtype*scale_data = scale_.mutalble_cpu_data();
int num = top[0]->num();
int dim = top[0]->count()/top[0]->num();
memcpy(bottom_diff,top_diff,sizeof(Dtype)*top[0]->count());
for (int i = 0;i<num; ++i){
scale_data[i] = caffe_cpu_dot<Dtype>(dim,top_diff + i*dim,
top_data + i*dim);
}
caffe_cpu_gemm<Dtype>(CblasNoTrans,CblasNoTrans,num,dim,1,-1,scale_data,sum_multipiler-.cpu_data9),1.,bottom_diff);
return Dtype(0);
}

INSTSANTIATE_CLASS(SoftmaxLayer);
}
