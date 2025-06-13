

#if !defined(__NameSorter_Name_h)
#define __NameSorter_Name_h

class Name
{
public:
   char* getNormalName(void);
   void setNormalName(char* newNormalName);
   char* getLowerCaseName(void);
   void setLowerCaseName(char* newLowerCaseName);
   void transformToLowerCase();
   void printName();
   Name(char* normalName);
   ~Name();

protected:
private:
   char* normalName;
   char* lowerCaseName;


};

#endif