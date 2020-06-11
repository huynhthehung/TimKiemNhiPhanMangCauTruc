// TimKiemNhiPhanMangCauTruc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
struct SanPham {
    int ma;
    char ten[150];
    float gia;
};
void NhapDanhSachSanPham(SanPham dssp[], int n);
void XuatDanhSachSanPham(SanPham dssp[], int n);
SanPham* TimSanPham(SanPham dssp[], int n, float giaTim);
int main()
{
    int n=0;
    SanPham dssp[10];
    cout << "Nhap so san pham: ";
    cin >> n;
    NhapDanhSachSanPham(dssp, n);
    cout << "San pham sau khi nhap: \n";
    XuatDanhSachSanPham(dssp, n);
    float giaTim;
    cout << "Nhap gia muon tim: ";
    cin >> giaTim;
    SanPham* sp = TimSanPham(dssp, n, giaTim);
    if (sp == NULL)
        cout << "Khong tim thay san pham co gia " << giaTim;
    else
        cout << sp->ma << "\t" << sp->ten << "\t" << sp->gia;
    return 0;
}

void NhapDanhSachSanPham(SanPham dssp[], int n)
{
    for (int i = 0; i < n; i++)
    {   
        cout << "Nhap san pham thu " << i+1 << endl;
        cout << "Nhap ma: ";
        cin >> dssp[i].ma;
        cout << "Nhap ten: ";
        cin >> dssp[i].ten;
        cout << "Nhap gia: ";
        cin >> dssp[i].gia;
    }
}

void XuatDanhSachSanPham(SanPham dssp[], int n)
{
    for (int i = 0; i < n; i++)
    {
        SanPham sp = dssp[i];
        cout << sp.ma << "\t" << sp.ten << "\t" << sp.gia << endl;
    }
    
}

SanPham* TimSanPham(SanPham dssp[], int n, float giaTim)
{
    int left = 0;
    int right = n - 1;
    int mid = 0;
    do
    {
        mid = (left + right) / 2;
        SanPham sp = dssp[mid];
        if (giaTim == sp.gia)
            return &dssp[mid];
        else
            if (sp.gia > giaTim)
                right = mid - 1;
            else
                left = mid + 1;
    } while (left <= right);
    return NULL;
}
