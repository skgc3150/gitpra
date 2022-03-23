#include<stdio.h>
#include<math.h>

//中点法で連星シュミレーション

const double m1 = 1, m2 = 2;
const double G = 10; //万有引力定数

//質点1と2の距離
double r(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

//x成分に働く力
double grax(double x1,double y1,double x2, double y2){
    return G*m1*m2*(x2-x1)/(pow(r(x1,y1,x2,y2),3));
}
//y成分に働く力
double gray(double x1,double y1,double x2, double y2){
    return G*m1*m2*(y2-y1)/(pow(r(x1,y1,x2,y2),3));
}

//重心点のx座標
double cgx(double x1,double y1,double x2, double y2){
    return (m1*x1+m2*x2)/(m1+m2);
}

//重心点のy座標
double cgy(double x1,double y1,double x2, double y2){
    return (m1*y1+m2*y2)/(m1+m2);
}

int main(){
    double t0,t1,x10,x20,vx10,vx20,y10,y20,vy10,vy20,x1,x2,vx1,vx2,y1,y2,vy1,vy2,vmax,dt;
    double k1x,k1y,k1vx,k1vy,k2x,k2y,k2vx,k2vy;
    int i,nint;

    t0=0;
    t1=50;

    x10=0;
    y10=2;
    vx10=-1;
    vy10=1;

    x20=0;
    y20=-2;
    vx20=1;
    vy20=-1;

    x1=x10;
    x2=x20;
    y1=y10;
    y2=y20;

    vx1=vx10;
    vx2=vx20;
    vy1=vy10;
    vy2=vy20;

    dt=0.001;
    nint=(t1-t0)/dt;
    for (int i = 0; i < nint; i++){
        printf("%f %f %f %f %f %f\n",x1,y1,x2,y2,cgx(x1,y1,x2,y2),cgy(x1,y1,x2,y2));
        k1x=x1+dt/2*vx1;
        k1y=y1+dt/2*vy1;
        k1vx=vx1+dt/2*(grax(x1,y1,x2,y2))/m1;
        k1vy=vy1+dt/2*(gray(x1,y1,x2,y2))/m1;

        k2x=x2+dt/2*vx2;
        k2y=y2+dt/2*vy2;
        k2vx=vx2+dt/2*(-grax(x1,y1,x2,y2))/m1;
        k2vy=vy2+dt/2*(-gray(x1,y1,x2,y2))/m1;
    
        x1=x1+dt*k1vx;
        y1=y1+dt*k1vy;
        vx1=vx1+dt*(grax(k1x,k1y,k2x,k2y))/m1;
        vy1=vy1+dt*(gray(k1x,k1y,k2x,k2y))/m1;

        x2=x2+dt*k2vx;
        y2=y2+dt*k2vy;
        vx2=vx2+dt*(-gray(k1x,k1y,k2x,k2y))/m2;
        vy2=vy2+dt*(-gray(k1x,k1y,k2x,k2y))/m2;

    }
    

}