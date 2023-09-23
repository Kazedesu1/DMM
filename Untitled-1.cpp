#include<iostream>
#include<math.h>

using namespace std;
int main ()
{
    class PHANSO
    {
        private:
        int tu,mau;
        public:
        void nhap()
        {
            cout <<endl<<"nhap vao tu so: "; cin >> this->tu;
            cout <<endl<<"nhap vao mau so: "; cin >> this->mau;
        }
        void in()
        {
            cout<<tu<<"/"<<mau;
        }
        int ucln()
        {
            int ucln;
            for(int i=1;i<=mau;i++)
                if(tu%i==0 && mau%i==0)
                ucln=i;
            return ucln;
        }
        void toigian()
        {
            int uc = ucln();
            tu /= uc;
            mau /= uc;
        }
        PHANSO cong(PHANSO &p2)
        {
            PHANSO tg;
            tg.tu=tu*p2.mau+mau*p2.tu;
            tg.mau = mau*p2.mau;
            tg.toigian();
            return (tg);
        }
        PHANSO tru(PHANSO &p2)
        {
            PHANSO tg;
            tg.tu=tu*p2.mau-mau*p2.tu;
            tg.mau = mau*p2.mau;
            tg.toigian();
            return (tg);
        }
        PHANSO nhan(PHANSO &p2)
        {
            PHANSO tg;
            tg.tu=tu*p2.tu;
            tg.mau = mau*p2.mau;
            tg.toigian();
            return (tg);
        }
        PHANSO chia(PHANSO &p2)
        {
            PHANSO tg;
            tg.tu=tu*p2.mau;
            tg.mau = mau*p2.tu;
            tg.toigian();
            return (tg);
        }
        bool sosanh(PHANSO p1,PHANSO p2){
        return(float(p1.tu)/p1.mau<float(p2.tu)/p2.mau);
    }
    };
    int n;
    cout <<endl<<"nhap so phan so: "; cin >> n;
    PHANSO *p = new PHANSO[n];
    cout <<endl<<"nhap day cac phan so: ";
    for(int i =0;i<n;i++)
    p[i].nhap();
    cout <<endl<<"day phan so vua nhap: ";
    for(int i =0;i<n;i++)
    {
    (p+i)->in();
    cout <<" ";
    }
    PHANSO tong = p[0] ,so ;
    for(int i=1;i<n;i++)
    tong = tong.cong(p[i]);
    cout <<endl<<"tong cua cac phan so la: " ;
    tong.in();
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        if(so.sosanh(p[j],p[i]))
        {
            PHANSO temp = p[i];
                    p[i] = p[j];
                    p[j] = temp;
        }
    }
    cout <<endl<<"sap xep theo tt giam dan: " ;
    for(int i =0;i<n;i++)
    {
    (p+i)->in();
    cout <<" ";
    }
}

