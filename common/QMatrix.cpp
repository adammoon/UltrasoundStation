#include "QMatrix.h"
#include "commonFunction.h"

#include "memory.h"

#define _2DADDRESS(i,j) ((w)*(i)+(j))

template <typename T> QMyMatrix<T>::QMyMatrix(T* srcData,const unsigned int width,const unsigned int height){
  Q_ASSERT(NULL!=srcData);
  if( NULL == srcData ){
    //在这里应该加入错误提示的信息，以便调用者知道错误或者异常的发生
    return;
  }
  w = width;
  h = height;
  dataBuffer = new T[w*sizeof(T)*h];
  if( NULL == srcData ){
    //提示错误
    return;
  }
}
//2
template <typename T> QMyMatrix<T>::QMyMatrix(const unsigned int width,
					  const unsigned int height)
{
    if( width <= 0 || height <= 0){
	this->dataBuffer = NULL;
	return;
    }
    w = width;
    h = height;
    dataBuffer = new T[w*h*sizeof(T)];
    memset(dataBuffer,0,w*h);
}
//
template <typename T> QMyMatrix<T>::QMyMatrix(QMyMatrix& m){
    w = m.w;
    h = m.h;
    dataBuffer = new T[w*h*sizeof(T)];
    memcpy(dataBuffer,m.dataBuffer,w*h);
}

//析够函数
template <typename T> QMyMatrix<T>::~QMyMatrix(){
  SAFE_DELETE(dataBuffer);
}
//At()
template <typename T> T QMyMatrix<T>::At(const UINT32 i,const UINT32 j)const{
    if(i <= 0 || i > w || j <= 0 || j > h)
    {
	return (T)(-1);
    }
    return *(dataBuffer + _2DADDRESS(i,j));
}
template <typename T> void QMyMatrix<T>::setAt(const UINT32 i,const UINT32 j,T &value){
    if(i <= 0 || i > w || j <= 0 || j > h)
    {
	return ;
    }
    *(dataBuffer + _2DADDRESS(i,j)) = value;
}
template <typename T> QMyMatrix<T>& QMyMatrix<T>::operator +(QMyMatrix<T>& m){
    if(w != m.w || h != m.h){
	return *this;
    }
    QMyMatrix<T> t(w,h);
    T tv;
    //ke yi zuo you hua
    UINT32 i,j;
    for( i = 1;i < w;i++){
	for( j = 1; j < h; j++){
	    tv = this->At(i,j) + m.At(i,j);
	    t.setAt(i,j,tv);
	}
    }
    return t;
}
template <typename T> QMyMatrix<T>& QMyMatrix<T>::operator *(QMyMatrix<T>& m){
    if (w != m.h || h != m.w){
	return *this;
    }
    QMyMatrix<T> t(h,m.w);
    T tv;
    UINT32 i,j,k;
    for(i = 1; i < h; i++){
	for( j = 1; j < m.w; j++){
	    tv = 0;
	    for (k = 1;k < w;k++){
		tv += this->At(i,k)*m.At(k,j);
	    }
	    t.setAt(i,j,tv);
	}
    }
    return t;
}
template <typename T> QMyMatrix<T>& QMyMatrix<T>::operator -(QMyMatrix<T>& m){
    Q_UNUSED(m);
    return *this;
}
template <typename T> QMyMatrix<T>& QMyMatrix<T>::operator /(QMyMatrix<T>& m){
    Q_UNUSED(m);
    return *this;
}
template <typename T> QMyMatrix<T>& QMyMatrix<T>::FourierTransfor(QMyMatrix<T>& m){
    //Q_UNUSED(m);
    return  m;
}
template <typename T> QMyMatrix<T>& QMyMatrix<T>::Convolution(QMyMatrix<T>& a,QMyMatrix<T>& b,QVariant& flag){
    //Q_UNUSED(m);
    return a;
}
template <typename T> UINT32 QMyMatrix<T>::getR(QMyMatrix<T>& m){
    Q_UNUSED(m);
    return w;
}
