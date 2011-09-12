#ifndef QMATRIX_H
#define QMATRIX_H
typedef unsigned int UINT32;
class QVariant;
/*!
  \class QMyMatrix
  \brief �Զ���ľ���ģ����
  \details Ϊ�˼򻯶�ͼ�����ݵĲ�������ͼ���е����ݲ�����ȡ��Ϊһ������
  ͬʱ�ܹ�ʹ�þ���Ԫ����Ż��ܹ���Ч�ķ�ӳ��ͼ�������У����������Ż�������.
  \author flyfish
  \sa <b>QImgAdpater<\b>
*/
template <typename T>
class QMyMatrix{
public:
    /*! ���캯��
      \param T* ���������Ԫ��λ�ã�������ȿ���Ϊ����ֵ��
      \param width ������
      \param height ����߶�
      \author flyfish
    */
    QMyMatrix(T*,const unsigned int width,const unsigned int height);
    /*! ���캯��2
      \param width ������
      \param height ����߶�
      \author flyfish
      */
    QMyMatrix(const unsigned int width,const unsigned int height);
    /*! ���ƹ��캯��
      \param m : �����ƾ���
      \author flyfish
      */
    QMyMatrix(QMyMatrix& m);
    /*! ��������
      */
    ~QMyMatrix();
    /*! UINT32�ڲ����͵Ķ��� */
    //typedef unsigned int UINT32;
    /*! ��ȡ�����е�i�У���j�е�����ֵ��i��j��1��ʼ����
      \param i:����
      \Param J:����
      \Return T& : �����Ӧλ�õ�ֵ
      \Author Flyfish
      */
    T At(const UINT32 I,const UINT32 J)const;
    /*! ���þ����еĵ�I�У���J�е�����,I,J��1��ʼ����
     \param I:��
     \param J:��
     \param T&:��ֵ
     \peturn Void
     \author Flyfish
     */
    void setAt(const UINT32 I,const UINT32 J,T& Value);
    /*! ����ӷ�����
     \param ���Ӿ���
     \return �;���
     \author flyfish
     */
    QMyMatrix& operator +(QMyMatrix&);
    /*! �������
      \param ��������
      \return �����
      \author flyfish
     */
    QMyMatrix& operator -(QMyMatrix&);
    /*! ����˷�
      \param ���˾���
      \return ������
      \author flyfish
    */
    QMyMatrix& operator *(QMyMatrix&);
    /*! �������
      \param ��������
      \param �̾���
      \author flyfish
     */
    QMyMatrix& operator /(QMyMatrix&);
    /*! ����ĸ���Ҷ�任
      \param ���任����
      \return �任���
    */
    static QMyMatrix& FourierTransfor(QMyMatrix&);
    /*! ����ľ�����㣬�������Բο�MATLAB��conv������˵��*/
    static QMyMatrix& Convolution(QMyMatrix&,QMyMatrix&,QVariant&);
    /*! �������Ret
      \param �������
      \return �������
     */
    UINT32 getR(QMyMatrix& m);
private:
    T* dataBuffer;      /*!< ���ݴ洢λ��*/
    unsigned int w,h;   /*!< �����Ⱥ͸߶�,��ʱ��ע������������Ŀ�Ĳ��*/
};

#endif // QMATRIX_H
