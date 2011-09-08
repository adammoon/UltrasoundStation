/*!
  \class 类名           <---在这里 要与HelloDoxygen相同
  \brief 简要描述        <-----在这里
  \details 详细描述      <-----在这里
  \author 作者          <-----here
  \date   日期
*/
class HelloDoxygen{
 public:
  /*!HelloDoxygen()函数说明写这里  <-----
   \param a:参数说明在这里，多个参数在下面继续使用\param
   \return 返回参数在这里
  */
  HelloDoxygen(int a);
   /*!内部结构定义示例
    \detail 详细说明在这里
   */
  typedef enum{
    TVal_1, /*!< 第一种的说明*/
    TVal_2  /*!< 第二种的说明*/
  }T;
  /*! 这是一个静态函数
   * \param a :int
   * \param b :int 
   * \return int value
   */
  static int f(int a,int b);
 private:
  //私有定义的默认情况下，是不会被文档化（未在文档中显示出来）
  int member_int; /*!< member of the HelloDoxygen*/
 public:
  //! a private function
  /*!
    test for private data 
  */
  int get();
  ////下面是一个更完善的函数注释块
  /*! set member_int' value
   * \param a value
   * \param b old value
   * \return operate is ok or not 
   * \sa get()
   * \author flyfish
   * \date 2011-09-7
   */
  bool set(int a,int b);
}
