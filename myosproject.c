#include<stdio.h>
#include<conio.h>

void nam(int no,int RemainTime[10],int CompTime,int Ariv_Time[10],int Bur_Time[10]);

int main()
{
	int Proc_No,j,no,CompTime,RemainProc,indic,Time_Quant,Wait,Tur_Arou_Time,Ariv_Time[10],Bur_Time[10],RemainTime[10],x=1;
	 indic = 0;
         Wait=0;
    Tur_Arou_Time = 0;
    printf("Enter the number of processes: ");
    scanf("%d",&no);
    RemainProc = no;
    
    
     printf("\nEnter the Arrival Time and Burst Time of the Processes:\n");
    for(Proc_No = 0;Proc_No < no;Proc_No++)
    {
        printf("\nProcess P%d\n",Proc_No+1);
        printf("Arrival Time = ");
        scanf("%d",&Ariv_Time[Proc_No]);
        printf("Burst time = ");
        scanf("%d",&Bur_Time[Proc_No]);
        RemainTime[Proc_No]=Bur_Time[Proc_No];
    }
    
     printf("The details for Time Quantum are as follows:\n");
    printf("The Time Quantum for First Round is 3.\n");
    Time_Quant=3;
    CompTime=0;
    for(Proc_No=0;RemainProc!=0;)
    {
        if(RemainTime[Proc_No]<=Time_Quant && RemainTime[Proc_No]>0)
        {
            CompTime+=RemainTime[Proc_No];
            RemainTime[Proc_No]=0;
            indic=1;
        }
        else if(RemainTime[Proc_No]>0)
        {
            RemainTime[Proc_No]-=Time_Quant;
            CompTime+=Time_Quant;
        }
    
     if(RemainTime[Proc_No]==0 && indic==1)
        { printf("%d",Proc_No);
            RemainProc--;
            printf("P %d",Proc_No+1);
            printf("\t\t\t%d",CompTime-Ariv_Time[Proc_No]);
            printf("\t\t\t%d\n",CompTime-Bur_Time[Proc_No]-Ariv_Time[Proc_No]);
          Wait+=CompTime-Ariv_Time[Proc_No]-Bur_Time[Proc_No];
            Tur_Arou_Time+=CompTime-Ariv_Time[Proc_No];
            indic=0;
            
        }
        if(Proc_No==no-1){
            x++;
            if(x==2){
                Proc_No=0;
                Time_Quant=6;
                
                printf("The Time Quantum for the second round is 6.\n");
				}
            else{
                break;
            }
        }
        else if(CompTime >= Ariv_Time[Proc_No+1]){
            Proc_No++;
        }
        else{
            Proc_No=0;
        }
    }
    
    nam(no,RemainTime,CompTime,Ariv_Time,Bur_Time);
    
    return 0;
}

    
    void nam(int no,int RemainTime[10],int CompTime,int Ariv_Time[10],int Bur_Time[10]){
    
    float Avg_Wait,AvgTur_Arou_Time;
    int i,j,n=no,Temp,BTime[20],Proc_No[20],WTime[20],Tur_Ar_Time[20],Total=0,loc;
    
    printf("Third round with least burst time.\n");
    
    for(i=0;i<n;i++)
    {
        BTime[i]=RemainTime[i];
        WTime[i]=CompTime-Ariv_Time[i]-Bur_Time[i];
        Proc_No[i]=i+1;
    }
    
    for(i=0;i<n;i++)
    {
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(BTime[j]<BTime[loc]){
                loc=j;
            }
        }
        Temp=BTime[i];
        BTime[i]=BTime[loc];
        BTime[loc]=Temp;
        Temp=Proc_No[i];
        Proc_No[i]=Proc_No[loc];
        Proc_No[loc]=Temp;
    }
    
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++){
            WTime[i]+=BTime[j];
        }
        Total+=WTime[i];
    }
    
    Avg_Wait=(float)Total/n;
    Total=0;
    printf("\nProcess\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        Tur_Ar_Time[i]=BTime[i]+WTime[i];
		       Total=Total + Tur_Ar_Time[i];
        printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d",Proc_No[i],BTime[i],WTime[i],Tur_Ar_Time[i]);
    }
    AvgTur_Arou_Time=(float)Total/n;
    printf("\n\nAverage waiting time = %f",Avg_Wait);
    printf("\n Average turnaround time = %f\n",AvgTur_Arou_Time);
    
}
