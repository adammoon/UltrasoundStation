#ifndef COMMONFUNCTION_H
#define COMMONFUNCTION_H
#ifndef SAFE_DELETE
#define SAFE_DELETE(pointer) if(0 != pointer){   \
                                delete pointer;     \
                                pointer = 0;}
#endif
#endif // COMMONFUNCTION_H
