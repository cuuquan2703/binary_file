#include <iostream>
#include <fstream>
using namespace std;

void writefile(const char* path)
{
    int n=4;
    int a[]={2,4,6,8};
    FILE *fin;
    fin = fopen(path, "wb");
    if (fin != NULL)
    {
        fwrite(&n, sizeof(int),1,fin);
        fwrite(a, sizeof(int),4,fin);
    }else{
        cout<<"Cannot open file"<<endl;
    }
    fclose(fin);
}

void readfile(const char* path)
{
    FILE* fout;
    fout=fopen(path, "rb");
    if (fout != NULL)
    {
        int val=0;
        fseek(fout, 3*sizeof(int), SEEK_SET );
        fread(&val,sizeof(int),1,fout);
        cout<<val;
    }else{
        cout<<"Cannot open file"<<endl;
    };
    fclose(fout);
}

int main() {
    writefile("out.bin");
    readfile("out.bin");
    return 0;
}
