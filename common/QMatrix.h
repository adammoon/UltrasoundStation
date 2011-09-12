#ifndef QMATRIX_H
#define QMATRIX_H
typedef unsigned int UINT32;
class QVariant;
/*!
  \class QMyMatrix
  \brief 自定义的矩阵模板类
  \details 为了简化对图像数据的操作，将图像中的数据部分提取成为一个矩阵
  同时能够使得矩阵元算的优化能够有效的反映到图像运算中，进而减少优化工作量.
  \author flyfish
  \sa <b>QImgAdpater<\b>
*/
template <typename T>
class QMyMatrix{
public:
    /*! 构造函数
      \param T* 矩阵的数据元素位置（采用深度拷贝为矩阵赋值）
      \param width 矩阵宽度
      \param height 矩阵高度
      \author flyfish
    */
    QMyMatrix(T*,const unsigned int width,const unsigned int height);
    /*! 构造函数2
      \param width 矩阵宽度
      \param height 矩阵高度
      \author flyfish
      */
    QMyMatrix(const unsigned int width,const unsigned int height);
    /*! 复制构造函数
      \param m : 被复制矩阵
      \author flyfish
      */
    QMyMatrix(QMyMatrix& m);
    /*! 析够函数
      */
    ~QMyMatrix();
    /*! UINT32内部类型的定义 */
    //typedef unsigned int UINT32;
    /*! 获取矩阵中第i行，第j列的数据值，i，j从1开始计数
      \param i:行数
      \Param J:列数
      \Return T& : 矩阵对应位置的值
      \Author Flyfish
      */
    T At(const UINT32 I,const UINT32 J)const;
    /*! 设置矩阵中的第I行，第J列的数据,I,J从1开始计数
     \param I:行
     \param J:列
     \param T&:新值
     \peturn Void
     \author Flyfish
     */
    void setAt(const UINT32 I,const UINT32 J,T& Value);
    /*! 矩阵加法运算
     \param 被加矩阵
     \return 和矩阵
     \author flyfish
     */
    QMyMatrix& operator +(QMyMatrix&);
    /*! 矩阵减法
      \param 被减矩阵
      \return 差矩阵
      \author flyfish
     */
    QMyMatrix& operator -(QMyMatrix&);
    /*! 矩阵乘法
      \param 被乘矩阵
      \return 积矩阵
      \author flyfish
    */
    QMyMatrix& operator *(QMyMatrix&);
    /*! 矩阵除法
      \param 被除矩阵
      \param 商矩阵
      \author flyfish
     */
    QMyMatrix& operator /(QMyMatrix&);
    /*! 矩阵的傅立叶变换
      \param 被变换矩阵
      \return 变换结果
    */
    static QMyMatrix& FourierTransfor(QMyMatrix&);
    /*! 矩阵的卷积运算，参数可以参考MATLAB的conv函数的说明*/
    static QMyMatrix& Convolution(QMyMatrix&,QMyMatrix&,QVariant&);
    /*! 矩阵的秩Ret
      \param 被求矩阵
      \return 矩阵的秩
     */
    UINT32 getR(QMyMatrix& m);
private:
    T* dataBuffer;      /*!< 数据存储位置*/
    unsigned int w,h;   /*!< 矩阵宽度和高度,需时刻注意其与行列数目的差别*/
};

#endif // QMATRIX_H
