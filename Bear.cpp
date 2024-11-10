#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Bear {
private:
    string MaBear;
    string TenBear;
    float DonGia;
    int SoLuong;

public:
    Bear() {}
    Bear(string mb, string tb, float dg, int sl) : MaBear(mb), TenBear(tb), DonGia(dg), SoLuong(sl) {}

    string getMaBear() const { return MaBear; }
    string getTenBear() const { return TenBear; }
    float getDonGia() const { return DonGia; }
    int getSoLuong() const { return SoLuong; }

    void setTenBear(const string& ten) { TenBear = ten; }
    void setDonGia(float donGia) { DonGia = donGia; }
    void setSoLuong(int soLuong) { SoLuong = soLuong; }

    friend istream& operator>>(istream& is, Bear& b) {
        cout << "Nhap ma bear: ";
        is >> b.MaBear;
        cout << "Nhap ten bear: ";
        is.ignore();
        getline(is, b.TenBear);
        cout << "Nhap don gia: ";
        is >> b.DonGia;
        cout << "Nhap so luong: ";
        is >> b.SoLuong;
        return is;
    }

    friend ostream& operator<<(ostream& os, const Bear& bear) {
        os << fixed << setprecision(2);
        os << "Ma Bear: " << bear.MaBear << "\n"
           << "Ten Bear: " << bear.TenBear << "\n"
           << "Don Gia: " << bear.DonGia << "\n"
           << "So Luong: " << bear.SoLuong;
        return os;
    }

    bool operator<(const Bear& other) const {
        return this->SoLuong < other.SoLuong;
    }
};
