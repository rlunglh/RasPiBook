// this is an include template file for picoc.  It is automatically opened whenever picoc is stated in interactive mode. It can also be included in program files. Edit tmpl.c to have any functions which you desite. It comes with some standard int, float and char defines and two "built in" functions.
int i,j,k,l,m;
float x,y,z;
char *ca,*cb;
#define pd(x) printf("%d\n",(x))
#define ps(x) printf("%s\n",(x))
#define q() picocexit()
// Color definitions
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x0700
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

