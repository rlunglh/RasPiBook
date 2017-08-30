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

void cats()
{
FILE * f;
f=fopen("/sys/devices/bone_capemgr9/slots","rt");
char buf[200];
while (!feeof(f));
{
fgets((char *)buf,f);
printf("%s\n",(char *)buf);
}
fclose(f);
}
void pfile(char * fname)
{
  FILE * f;
  f=fopen(fname,"rt");
  char buf[257];
  while (!feof(f))
  {
  fgets((char *)buf,256,f);
  if (!feof(f)) printf("%s",(char *)buf);
  
  }
  fclose(f);
}
void Fonts(int size)
{
Clear(WHITE);
if (size>16) size=16;
int i;
char b[2];b[1]=0;
char n[10];
for (i=0;i<128;i++) {b[0]=i;sprintf((char *)n,"%d",i);printString(5,143,0,0xffff,(char*)n,2);printString(5,1,i*8,0xffff,(char*)b,size);Sleep(500000);}
printString(5,1,0,0xffff," ",size);printString(5,143,0,0xffff,"   ",2);
}

void memleak()
{
panelInit();
int i;
for (;;) { Clear(0);
Sleep(100);Clear(0xffff);Sleep(100);drawFile("beagle.png");Sleep(100);
}
}
void slides()
{
   int i=0;
   for (;;)
   {
      drawFile("beagle.png");Sleep(3000000);
      drawFile("pooh.png");Sleep(3000000);
      drawFile("piglet.png");Sleep(3000000);
      drawFile("gumby.png");Sleep(3000000);
   }
}

void vf()
{
	fill(0,0,0);
	selectFont("Sans",0,0);
	fontSize(20);
	fontColor(1,1,1);
}
