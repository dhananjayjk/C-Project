#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define getch getchar
typedef struct stud
{
	int rno;
	char nm[30];
	char pw[30];
	int p,m,c,tot,r;
	int a[3];
}Student;
void ranks(Student *,int);
int main()
{
    int opt,n,i,j,k=1,no,flg=0,c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,opt1;
    long len;
    char passw[20],ch,pw[20];
    char dtep[]="DTE";
    int bl[6][5]={0};
    Student s,p;
    FILE *fp,*fp1,*fp2,*fp3,*CSE,*IT,*MECH,*ELN,*ELE,*CIV;
    fp=fopen("Registration1.dat","a+b");
    fp1=fopen("Rankswce1.dat","a+b");
    fp2=fopen("RankList1.dat","w+b");
    fp3=fopen("Branch1.dat","a+b");
    CSE=fopen("CSE1.dat","w+b");
    IT=fopen("IT1.dat","w+b");
    MECH=fopen("MECH1.dat","w+b");
    ELN=fopen("ELN1.dat","w+b");
    ELE=fopen("ELE1.dat","w+b");
    CIV=fopen("CIV1.dat","w+b");

    while(1)
    {
        system("COLOR b3");

         printf("\nWELCOME\n\t1.DTE\n\t2.STUDENT\n\t3.Exit\n");
         scanf("%d",&opt);
         if(opt>2)
          break;
         switch(opt)
         {
              case 1:
                    printf("Enter Password :");
                    i=0;
                    while((ch=getch())!=13)
                    {
                        printf("*");
                        if(ch!=13)
                        passw[i]=ch;
                        k=i;
                        i++;
                    }

                if(strcmp(passw,dtep)!=0)
                {
                    printf("\nInvalid password you can't enter\n %s",pw);
                    break;
                }
                while(1)
                {
                   printf("\n\n***DTE***\n");
                   printf("1.EnterData\n2.Get Student Data \n3.RankList\n4.Allocation\n5.Exit\nChoice :");
                   scanf("%d",&opt);
                   system("COLOR 5f");

                   if(opt>4)
                    break;
                   if(opt==1)
                   {
                         printf("Enter No :");
                         scanf("%d",&no);
                         rewind(fp); //fseek
                         rewind(fp1);
                         flg=0;
                         while(fread(&s,sizeof(Student),1,fp)==1)
                         {
                              if(s.rno==no)
                              {
                                    while(fread(&p,sizeof(Student),1,fp1)==1)
                                    {
                                          if(p.rno==no)
                                          {
                                                  flg=1;break;
                                          }
                                    }
                                    if(flg==1)
                                    {
                                            printf("Already updated the data");break;
                                    }
                                    if(flg==0)
                                    {
                                      printf("Enter maths marks :");
                                      scanf("%d",&s.m);
                                      printf("Enter physics marks :");
                                      scanf("%d",&s.p);
                                      printf("Enter chemistry marks :");
                                      scanf("%d",&s.c);
                                      s.tot=s.p+s.m+s.c;
                                      s.r=s.rno;
                                      flg=1;
                                      rewind(fp1);
                                      fwrite(&s,sizeof(Student),1,fp1);
                                      printf("Saved the Data");
                                      break;
                                  }
                              }
                         }
                        if(flg==0)
                              printf("This student is not registered for exam");
                   }
                   if(opt==2)
                   {
                            rewind(fp1);
                          printf("\nRegi No ||    Name     ||  Total  ||  Maths  ||  Physics || Chemistry ||");

                        while(fread(&s,sizeof(Student),1,fp1)==1)
                        {
                                   printf("  \n%2d      || %-10s  ||   %3d   ||   %3d   ||  %3d     ||    %3d    ||",s.rno,s.nm,s.tot,s.m,s.p,s.c);
                        }
                   }
                    if(opt==3)
                    {
                                  fseek(fp1,0,SEEK_END);
                                  len=ftell(fp1);
                                  rewind(fp1);
                                  n=len/sizeof(Student);
                                  printf("No of students :%d",n);
                                  Student *arr;
                                  arr=(Student *)malloc(n*sizeof(Student));
                                  for(i=0;i<n;i++)
                                  {
                                      fread(&arr[i],sizeof(Student),1,fp1);
                                     // printf("\nRoll No:%2d  Name:%-10s  Rank:%2d   Total :%3d   Maths: %3d   Physics: %3d   Chemistry :%3d",arr[i].rno,arr[i].nm,arr[i].r,arr[i].tot,arr[i].m,arr[i].p,arr[i].c);
                                  }
                                  ranks(arr,n);
                                  printf("\n--------------------------------------------------------------------------------"
                                         "\n*************************************RESULT*************************************\n");
                                  printf("\nRank || Regi No ||    Name     ||  Total  ||  Maths  ||  Physics || Chemistry ||");
                                  rewind(fp2);
                                  for(i=0;i<n;i++)
                                  {
                                             printf("\n %2d  ||   %2d    || %-10s  ||   %3d   ||   %3d   ||  %3d     ||    %3d    ||",arr[i].r,arr[i].rno,arr[i].nm,arr[i].tot,arr[i].m,arr[i].p,arr[i].c);
                                             fwrite(&arr[i],sizeof(Student),1,fp2);
                                   //printf("\nRoll No:%2d  Name:%-10s  Rank:%2d   Total :%3d   Maths: %3d   Physics: %3d   Chemistry :%3d",arr[i].rno,arr[i].nm,arr[i].r,arr[i].tot,arr[i].m,arr[i].p,arr[i].c);
                                  }
                                   free(arr);
                                    break;
                    }
                    if(opt==4)
                    {
                            rewind(fp3);
                        fseek(fp3,0,SEEK_END);
                                  len=ftell(fp3);
                                  rewind(fp3);
                                  n=len/sizeof(Student);

//arr fp32
                                  for(i=0;i<n;i++)
                                  {

                                      fread(&s,sizeof(Student),1,fp3);
                                     // printf("\nRoll No:%2d  Name:%-10s  Rank:%2d   Total :%3d   Maths: %3d   Physics: %3d   Chemistry :%3d",arr[i].rno,arr[i].nm,arr[i].r,arr[i].tot,arr[i].m,arr[i].p,arr[i].c);
                                        if(s.r==i+1)
                                        {
                                            rewind(fp3);
                                            for(j=0;j<3;j++)
                                            {
                                               if(s.a[j]==1&&c1<5)
                                                {
                                                    fwrite(&s,sizeof(Student),1,CSE);
                                                    c1++;
                                                    break;
                                                }

                                                if(s.a[j]==2&&c2<5)
                                                 {
                                                    fwrite(&s,sizeof(Student),1,IT);
                                                    c2++;
                                                    break;
                                                 }

                                                if(s.a[j]==3&&c3<5)
                                                {
                                                    fwrite(&s,sizeof(Student),1,MECH);
                                                    c3++;
                                                    break;
                                                }

                                                if(s.a[j]==4&&c4<5)
                                                {
                                                    fwrite(&s,sizeof(Student),1,ELN);
                                                    c4++;
                                                    break;
                                                }
                                                if(s.a[j]==5&&c5<5)
                                                {
                                                    fwrite(&s,sizeof(Student),1,ELE);
                                                    c2++;
                                                    break;
                                                }
                                                if(s.a[j]==6&&c6<5)
                                                {
                                                    fwrite(&s,sizeof(Student),1,CIV);
                                                    c6++;
                                                    break;
                                                }
                                            }
                                        }
                                   }


                    }
              }
          break;
          case 2:
                  while(1)
                  {
                      system("COLOR f0");
                      printf("\n\n***Welcome Students***\n1. Registration\n2. Your Rank\n3. Enter Preferences\n4.Allotment\n5.Exit\nOPTION : ");
                      scanf("%d",&opt);


                      if(opt>4)
                         break;
                      switch(opt)
                      {

                          case 1:
                                fseek(fp,0,SEEK_END);
                               len=ftell(fp);
                               rewind(fp);
                               n=len/sizeof(Student);
                               s.rno=++n;
                               printf("Your Registeration No is %d\n",s.rno);
                               printf("Enter Name:");
                               scanf("%s",s.nm);
                               printf("Enter Password:");
                               s.r=n;
                                i=0;
                                while((ch=getch())!=13)
                                            {
                                             printf("#");
                                                if(ch!=13)
                                                s.pw[i]=ch;
                                            i++;
                                            }
                                            s.pw[i]='\0';


//                               scanf("%s",&s.pw);
                               fwrite(&s,sizeof(Student),1,fp);
                                break;

                          case 2:
                                   printf("Enter Registration No:");
                                   scanf("%d",&no);

                                   flg=0;
                                    rewind(fp2);
 //                                   fwrite(&s,sizeof(Student),1,fp2);
   //                                 printf("%d%d",s.rno,fread(&s,sizeof(Student),1,fp2));
                                   while(fread(&s,sizeof(Student),1,fp2)==1) //==1
                                   {

                                        if(s.rno==no)
                                        {
                                             flg=1;
                                             printf("Enter Password:");
                                             //scanf("%s",&passw);

                                             i=0;
                                              while((ch=getch())!=13)
                                              {
                                                    printf("*");
                                                    if(ch!=13)
                                                    passw[i]=ch;
                                                    k=i;
                                                   i++;
                                              }
                                              passw[i]='\0';

                                              if(strcmp(s.pw,passw)!=0)
                                              {
                                               printf("\nInvalid password you can't enter\n");
                                                break;
                                              }

                                             printf("\nYour Rank is :%d",s.r);

                                             break;
                                        }
                                   }
                                   if(flg==0)
                                        printf("You entered wrong registration no. or you have not attempted exam");
                                   break;

                          case 3:
                                    printf("Enter Registration No:");
                                    scanf("%d",&no);
                                    rewind(fp2);
                                    while(fread(&s,sizeof(Student),1,fp2)==1)
                                    {
                                        if(no==s.rno)
                                        {
                                            printf("Hi %s Enter Your Choice",s.nm);
                                            printf("Enter Password:");
                                             i=0;
                                              while((ch=getch())!=13)
                                              {
                                                    printf("*");
                                                    if(ch!=13)
                                                    passw[i]=ch;
                                                    k=i;
                                                   i++;
                                              }
                                              passw[i]='\0';

                                              if(strcmp(s.pw,passw)!=0)
                                              {
                                               printf("\nInvalid password you can't enter\n");
                                                break;

                                              }
                                                for(i=0;i<3;i++)
                                                {
                                                //s.a[i]=(char *)malloc(20*sizeof(char));
                                                printf("*Branches*:\n1.CSE\t2.MECH\t3.IT\t4.ELECTRONIX\t5.ELECTRICAL\t6.CIVIL\nYour  %d Choice:",i+1);
                                                scanf("%d",&opt);
                                                if(opt>6)
                                                    break;
                                                switch(opt)
                                                {
                                                    case 1:
                                                            s.a[i]=opt;
                                                            for(j=0;j<5;j++)
                                                            if(bl[0][j]==0)
                                                            {bl[0][j]=s.rno;break;}
                                                            break;
                                                    case 2:
                                                            s.a[i]=opt;
                                                            for(j=0;j<5;j++)
                                                            if(bl[1][j]==0)
                                                            {bl[1][j]=s.rno;break;}
                                                            break;
                                                    case 3:
                                                            s.a[i]=opt;
                                                            for(j=0;j<5;j++)
                                                            if(bl[2][j]==0)
                                                            {bl[2][j]=s.rno;break;}
                                                            break;
                                                    case 4:
                                                            s.a[i]=opt;
                                                            for(j=0;j<5;j++)
                                                            if(bl[3][j]==0)
                                                            {bl[3][j]=s.rno;break;}
                                                            break;
                                                    case 5:
                                                            s.a[i]=opt;
                                                            for(j=0;j<5;j++)
                                                            if(bl[4][j]==0)
                                                            {bl[4][j]=s.rno;break;}
                                                            break;
                                                    case 6:
                                                            s.a[i]=opt;
                                                            for(j=0;j<5;j++)
                                                            if(bl[5][j]==0)
                                                            {bl[5][j]=s.rno;break;}
                                                            break;
                                                    }
                                           }
                                        fwrite(&s,sizeof(Student),1,fp3);
                                }
                            }
                            break;
                        case 4:
                            {
                                        rewind(CSE);
                                        rewind(IT);
                                        rewind(MECH);
                                        rewind(ELN);
                                        rewind(CIV);
                                        rewind(ELE);
                                        Student *tmp;
                                        printf("branch list\n1.CSE\n2.IT\n3.MECH\n4.ELN\n5.ELECTRIAL\n6.CIVIL\n7.exit\nYOUR CHOICE : ");
                                        scanf("%d",&opt1);
                                        if(opt1>6)
                                            break;
                                        switch(opt1)
                                        {

                                            case 1:
                                                printf("\n_____CSE____\nRank || Regi No ||    Name     ||  Total  ||  Maths  ||  Physics || Chemistry ||");
                                                for(j=0;j<5;j++)
                                                {
                                                    fread(&s,sizeof(s),1,CSE);
                                                    if(feof(CSE))
                                                        break;
                                                    printf("  \n%2d      || %-10s  ||   %3d   ||   %3d   ||  %3d     ||    %3d    ||",s.rno,s.nm,s.tot,s.m,s.p,s.c);
                                                }
                                                break;
                                             case 2:
                                                 printf("\nRank || Regi No ||    Name     ||  Total  ||  Maths  ||  Physics || Chemistry ||");
                                                for(j=0;j<5;j++)
                                                {
                                                    fread(&s,sizeof(s),1,IT);
                                                    if(feof(IT))
                                                        break;
                                                    printf("  \n%2d      || %-10s  ||   %3d   ||   %3d   ||  %3d     ||    %3d    ||",s.rno,s.nm,s.tot,s.m,s.p,s.c);
                                                }
                                                break;
                                             case 3:
                                                 printf("\nRank || Regi No ||    Name     ||  Total  ||  Maths  ||  Physics || Chemistry ||");
                                                for(j=0;j<5;j++)
                                                {
                                                    fread(&s,sizeof(s),1,MECH);
                                                    if(feof(MECH))
                                                        break;
                                                    //printf("\nRank || Regi No ||    Name     ||  Total  ||  Maths  ||  Physics || Chemistry ||");
                                                    printf("  \n%2d      || %-10s  ||   %3d   ||   %3d   ||  %3d     ||    %3d    ||",s.rno,s.nm,s.tot,s.m,s.p,s.c);

                                                }
                                                break;
                                             case 4:
                                                 printf("\nRank || Regi No ||    Name     ||  Total  ||  Maths  ||  Physics || Chemistry ||");
                                                for(j=0;j<5;j++)
                                                {
                                                    fread(&s,sizeof(s),1,ELN);
                                                    if(feof(ELN))
                                                        break;
                                                  //  printf("\nRank || Regi No ||    Name     ||  Total  ||  Maths  ||  Physics || Chemistry ||");
                                                    printf("  \n%2d      || %-10s  ||   %3d   ||   %3d   ||  %3d     ||    %3d    ||",s.rno,s.nm,s.tot,s.m,s.p,s.c);

                                                }
                                                break;
                                             case 5:
                                                 printf("\nRank || Regi No ||    Name     ||  Total  ||  Maths  ||  Physics || Chemistry ||");
                                                for(j=0;j<5;j++)
                                                {
                                                    fread(&s,sizeof(s),1,ELE);
                                                    if(feof(ELE))
                                                        break;
                                                    //printf("\nRank || Regi No ||    Name     ||  Total  ||  Maths  ||  Physics || Chemistry ||");
                                                    printf("  \n%2d      || %-10s  ||   %3d   ||   %3d   ||  %3d     ||    %3d    ||",s.rno,s.nm,s.tot,s.m,s.p,s.c);

                                                }
                                                break;
                                             case 6:
                                                 printf("\nRank || Regi No ||    Name     ||  Total  ||  Maths  ||  Physics || Chemistry ||");
                                                for(j=0;j<5;j++)
                                                {
                                                    fread(&s,sizeof(s),1,CIV);
                                                    if(feof(CIV))
                                                        break;
                                                 //   printf("\nRank || Regi No ||    Name     ||  Total  ||  Maths  ||  Physics || Chemistry ||");
                                                    printf("  \n%2d      || %-10s  ||   %3d   ||   %3d   ||  %3d     ||    %3d    ||",s.rno,s.nm,s.tot,s.m,s.p,s.c);

                                                }
                                                break;
                                   }
                                  // fwrite(&s,sizeof(Student),1,fp3);
                            }


                      }
                  }
                  break;
          }
    }
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(CSE);
    fclose(IT);
    fclose(MECH);
    fclose(ELE);
    fclose(CIV);
    fclose(ELN);
}
void ranks(Student *arr,int n)
{
    int i,j;
    Student tmp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
          if(arr[i].tot<arr[j].tot)
            {
                arr[i].r=j+1;
                arr[j].r=i+1;
                tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
            else if(arr[i].tot==arr[j].tot)
            {
                if(arr[i].m<arr[j].m){
                arr[i].r=j+1;
                arr[j].r=i+1;
                tmp=arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
                }
                else if(arr[i].m==arr[j].m){
                    if(arr[i].p<arr[j].p){
                    arr[i].r=j+1;
                    arr[j].r  =i+1;
                    tmp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=tmp;
                    }
                    else if(arr[i].p==arr[j].p){

                        if(arr[i].c<arr[j].c)
                        {
                        arr[i].r=j+1;
                        arr[j].r=i+1;

                        tmp=arr[i];
                        arr[i]=arr[j];
                        arr[j]=tmp;

                        }
                }
            }
        }
    }
}
}
