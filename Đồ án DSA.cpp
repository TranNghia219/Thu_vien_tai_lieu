#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct SinhVien{
    string MSSV;
    string ten;
};

struct TaiLieu{
    string Ten;
    string masach;
};

struct PhieuMuonSach{
    SinhVien sv;
    TaiLieu tl;
    bool DangMuon;
    string NgayMuon;
};

vector<SinhVien> danhSachSV;
vector<TaiLieu> danhSachTL;
vector<PhieuMuonSach> danhSachMuon;

void themSinhVien(){
    SinhVien sv;
    cout<<"Nhap ma so sinh vien";
    cin>> sv.MSSV;
    cout<<"Nhap ten sinh vien";
    getline(cin,sv.ten);
    danhSachSV.push_back(sv);
}
void xoaThanhVien(){
    string MSSV;
    cout<<"Nhap MSSV: ";
    cin>>MSSV;
    int vt=timSinhVien(MSSV);
    if(vt==-1){
        cout<<"Khong tim thay sinh vien!\n";
        return;
    }
    for(int i=0;i<danhSachMuon.size();i++){
        if(danhSachMuon[i].sv.MSSV==MSSV&&danhSachMuon[i].DangMuon){
            cout<<"Sinh vien dang muon tai lieu, khong the xoa!\n";
            return;
        }
    }
    danhSachSV.erase(danhSachSV.begin()+vt);
    cout<<"Xoa thanh vien thanh cong!\n";
}
void themTaiLieu(){
    TaiLieu tl;
    cout<<"Nhap ma sach";
    cin>>tl.masach;
    cout<<"nhap ten sach";
    getline(cin,tl.Ten);
    danhSachTL.push_back(tl);
}
int timSinhVien(string MSSV){
    for(int i=0;i<danhSachSV.size();i++){
        if(danhSachSV[i].MSSV==MSSV)
            return i;
    }
    return -1;
}
int timTaiLieu(string masach){
    for(int i=0;i<danhSachTL.size();i++){
        if(danhSachTL[i].masach==masach)
            return i;
    }
    return -1;
}
void traCuuThanhVien(){
    string MSSV;
    cout<<"Nhap MSSV: ";
    cin>>MSSV;

    int vt=timSinhVien(MSSV);

    if(vt==-1){
        cout<<"Khong tim thay thanh vien!\n";
        return;
    }

    cout<<"MSSV: "<<danhSachSV[vt].MSSV<<'\n';
    cout<<"Ten: "<<danhSachSV[vt].ten<<'\n';

    bool dangMuon=false;

    for(int i=0;i<danhSachMuon.size();i++){
        if(danhSachMuon[i].sv.MSSV==MSSV&&danhSachMuon[i].DangMuon){
            if(!dangMuon){
                cout<<"Cac tai lieu dang muon:\n";
                dangMuon=true;
            }

            cout<<danhSachMuon[i].tl.masach
                <<" - "<<danhSachMuon[i].tl.Ten<<'\n';
        }
    }

    if(!dangMuon)
        cout<<"Hien tai khong muon tai lieu nao!\n";
}
bool dangDuocMuon(string masach){
    for(int i=0;i<danhSachMuon.size();i++){
        if(danhSachMuon[i].tl.masach==masach&&danhSachMuon[i].DangMuon)
            return true;
    }
    return false;
}
void muonSach(){
    string MSSV,masach,ngay;
    cout<<"Nhap MSSV: ";
    cin>>MSSV;

    int i=timSinhVien(MSSV);
    if(i==-1){
        cout<<"Khong tim thay sinh vien!\n";
        return;
    }

    cout<<"Nhap ma sach: ";
    cin>>masach;

    int j=timTaiLieu(masach);
    if(j==-1){
        cout<<"Khong tim thay tai lieu!\n";
        return;
    }

    if(dangDuocMuon(masach)){
        cout<<"Tai lieu dang duoc muon!\n";
        return;
    }
    cout<<"Nhap ngay muon: ";
    cin>>ngay;
    PhieuMuonSach p;
    p.sv=danhSachSV[i];
    p.tl=danhSachTL[j];
    p.DangMuon=true;
    p.NgayMuon=ngay;

    danhSachMuon.push_back(p);
    cout<<"Muon sach thanh cong!\n";
}
void traSach(){
    string MSSV,masach;
    cout<<"Nhap MSSV: ";
    cin>>MSSV;
    cout<<"Nhap ma sach: ";
    cin>>masach;
    for(int i=0;i<danhSachMuon.size();i++){
        if(danhSachMuon[i].sv.MSSV==MSSV&&
           danhSachMuon[i].tl.masach==masach&&
           danhSachMuon[i].DangMuon){

            danhSachMuon[i].DangMuon=false;

            cout<<"Tra sach thanh cong!\n";
            return;
        }
    }
    cout<<"Khong tim thay phieu muon!\n";
}