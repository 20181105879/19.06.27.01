#include <iostream>
#include <algorithm>
#include <cstdio>
#define Student_number 5
#define Teacher_number 7
using namespace std;
long long i,j;
//写的标题
char headline[10000]={"学号-------姓名---性别-学院--班级----分数----2-----3------4------5------6------7-----号码\n"};
//屏幕显示的标题
char output_headline[1000]={"学号------名字-性别-学院----班级---平均分--号码 "};
//读的标题
char show_headline1[10000]={"学号-------姓名---性别-学院--班级----分数----2-----3------4------5------6------7-----号码---平均分\n"};
//{"学号-------姓名------性别--学院---班级-------分数2--3--4--5--6--7-号码\n"};
char headline1[10000];
//学生结构体 （写）
struct Students{
    char id[15];
    char name[10];
    char sex[15];
    char college[15];
    char st_class[15];
    long long phone;
    double sore[Teacher_number];
    double avg;
    double sum;
    
}student[Student_number];

//学生结构体（读）
struct Students1{
    char id[15];
    char name[10];
    char sex[15];
    char college[15];
    char st_class[15];
    double sore[Teacher_number];
    double avg;
    double sum;
    long long phone;
}student1[Student_number];

struct Teachers{
    
    char name[30];
    char  id[15];
    double sore[Student_number];
    char sex[10];
    
}teacher[Teacher_number];

//给结构体排序
bool cmp( Students1  &p1,Students1 &p2)
{
    if(p1.avg>p2.avg)
    {
        return 1;
    }
    else if(p1.avg==p2.avg)
    {
        if(p1.name-p2.name>0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
        
    }
    else
    {
        return 0;
    }
}
viod Define_Students()
{
    //自己给写学生数据
    Students student[Student_number]=
    {
        
        //------学号-------姓名-----性别---学院---班级-------分数2--3--4--5--6--7-号码
        //                                                   号码
        //        {"2018110","邱健军","男","机械", "机械工程" ,72,72,72,72,72,72,72,1008611},
        //        {"2018111","二胖", "女" ,"医学院","护理学"  ,88,88,88,88,88,88,88,1008612},
        //        {"2018112","教授", "男" ,"计算机","飞机学"  ,99,99,99,99,99,99,99,1008613},
        //        {"2018113","蜗牛", "人妖", "鬼知道","你猜啊" ,11,11,11,11,11,11,11,1008614},
        //        {"2018114","阳建波","男","计科院","软件工程" ,22,22,22,22,22,22,22,1008615}
        
        {"2018110","邱健军","男","机械", "机械工程",1008611},
        {"2018111","二胖", "女" ,"医学院","护理学"  ,1008612},
        {"2018112","教授", "男" ,"计算机","飞机学"  ,1008613},
        {"2018113","蜗牛", "人妖", "鬼知道","你猜啊" ,1008614},
        {"2018114","阳建波","男","计科院","软件工程" ,1008615}
    };
}

viod Write_Students.txt()
{
    FILE *p=NULL;
    p=fopen("student.txt","w");
    if(!p)
    {
        printf("open fail\n");
        return 0;
    }
    // 给文本一个标题
    fprintf(p,"%s",headline);
    for( i=0;i<Student_number;i++)
    {
        fprintf(p,"%s  ",student[i].id);
        fprintf(p,"%s  ",student[i].name);
        fprintf(p,"%s    ",student[i].sex);
        fprintf(p,"%s  ",student[i].college);
        fprintf(p,"%s  ",student[i].st_class);
        fprintf(p,"%s  \n",student[i].phone);
    }
    
    fclose(p);
    
}


viod Read_student.txt()
{
    FILE *fp=NULL;
    fp=fopen("student.txt","r");
    if(!fp)
    {
        printf("open fail\n");
        return 0;
    }
    
    fscanf(p,"%s",headline1);
    for(i=0;i<Student_number;i++)
    {
        
        fscanf(p,"%s",student1[i].id);
        fscanf(p,"%s",student1[i].name);
        fscanf(p,"%s",student1[i].sex);
        fscanf(p,"%s",student1[i].college);
        fscanf(p,"%s",student1[i].st_class);
        fscanf(p,"%lld",&student1[i].phone);
    }
    fclose(p);
    
}
viod Read_teacher.txt()
{
    FILE *p1=NULL;
    p1=fopen("teacher.txt","r");
    if(!p1)
    {
        printf("open false\n");
        return 0;
    }
    for(i=0;i<Teacher_number;i++)
    {
        fscanf(p1,"%s %s",teacher[i].id,teacher[i].name);
        fscanf(p1,"%s",teacher[i].sex);
        for(j=0;j<Student_number;j++)
        {
            fscanf(p1,"%lf",&teacher[i].sore[j]);
            student[j].sore[i]=teacher[i].sore[j];
            
        }
        
    }
    fclose(p1);
}



viod Save_show.txt()
{
    FILE *pp=NULL;
    pp=fopen("show.txt","w");
    if(!pp)
    {
        printf("open false1\n");
        return 0;
    }
    
    fprintf(pp,"%s\n",show_headline1);
    for(i=0;i<Student_number;i++)
    {
        fprintf(pp,"%s  ",student1[i].id);
        fprintf(pp,"%s  ",student1[i].name);
        fprintf(pp,"%s    ",student1[i].sex);
        fprintf(pp,"%s  ",student1[i].college);
        fprintf(pp,"%s  ",student1[i].st_class);
        for(int j=0;j<Teacher_number;j++)
        {
            fprintf(pp,"%.2f  ",student1[i].sore[j]);
        }
        fprintf(pp,"%lld   ",student1[i].phone);
        fprintf(pp,"%.2f",student1[i].avg);
        fprintf(pp,"\n");
        
    }
    fclose(pp);
}
viod Show_Reselt()
{
    printf("%s\n",output_headline);
    for(i=0;i<Student_number;i++)
    {
        printf("rank %d:\n",(i+1));
        printf("%s  %s  %s  ",student1[i].id,student1[i].name,student1[i].sex);
        printf("%s  %s  ",student1[i].college,student1[i].st_class);
        printf("%.2f  %lld\n",student1[i].avg,student1[i].phone);
        printf("\n");
    }
}
void Copy_score()
{
    for(i=0;i<Teacher_number;i++)
    {
        for(j=0;j<Student_number;j++)
        {
            student[j].sore[i]=teacher[i].sore[j];
        }
    }
}
void viod Dealwith_score()
{
    for(i=0;i<Student_number;i++)
    {
        sort(student[i].sore,student[i].sore+Teacher_number)
        student[i].sum=0;
        for(j=1;j<Teacher_number-1;j++)
        {
            student[i].sum+=student[i].sore[j];
        }
        student[i].avg=student[i].sum/(Teacher_number-2);
    }
}
int main()
{
    viod Define_Students();
    viod Write_Students.txt();
    viod Read_student.txt();
    viod Read_teacher.txt();
    viod Copy_score();
    viod Dealwith_score();
    sort(student1,student1+Student_number,cmp);
    viod Save_show.txt();
    viod Show_Reselt();
    
    return 0;
}
