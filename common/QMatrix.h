#ifndef QMATRIX_H
#define QMATRIX_H
class QVariant;
template <typename T>
class QMyMatrix{
public:
    QMyMatrix(T*);
    ~QMyMatrix();
    typedef unsigned int UINT32;
    T* At(const UINT32 i,const UINT32 j)const;
    void setAt(const UINT32 i,const UINT32 j,T* value);
    QMyMatrix& operator +(QMyMatrix&);
    QMyMatrix& operator -(QMyMatrix&);
    QMyMatrix& operator *(QMyMatrix&);
    QMyMatrix& operator /(QMyMatrix&);
    static QMyMatrix& FourierTransfor(QMyMatrix&);
    static QMyMatrix& Convolution(QMyMatrix&,QMyMatrix&,QVariant&);
private:
    T* dataBuffer;
    unsigned int w,h;
};

#endif // QMATRIX_H
