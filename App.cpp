#include <iostream>
#include "BearList.cpp"

using namespace std;

class App {
private:
    BearList bearList;

public:
    void menu() {
        bool kt = true;
        while (kt) {
            cout << "\n=== MENU ===\n";
            cout << "1. Nhap danh sach bear\n";
            cout << "2. Xuat danh sach bear\n";
            cout << "3. Sap xep danh sach bear\n";
            cout << "4. Them bear\n";
            cout << "5. Tim kiem bear theo ma\n";
            cout << "6. Tim max/min don gia bear\n";
            cout << "7. Xoa bear theo ma\n";
            cout << "8. Sua bear theo ma\n";
            cout << "9. Luu danh sach bear ra file\n";
            cout << "0. Thoat\n";

            int choice;
            cout << "Nhap lua chon: "; 
            cin >> choice;

            switch (choice) {
                case 1: bearList.Nhap(); break;
                case 2: bearList.Xuat(); break;
                case 3: bearList.SapXep(); break;
                case 4: {
                    Bear b;
                    cout << "Nhap thong tin bear moi: ";
                    cin >> b;
                    bearList.ThemBear(b);
                    break;
                }
                case 5: {
                    string maBear;
                    cout << "Nhap ma bear can tim: ";
                    cin >> maBear;
                    bearList.TimKiemBear(maBear);
                    break;
                }
                case 6: bearList.MaxMin(); break;
                case 7: {
                    string maBear;
                    cout << "Nhap ma bear can xoa: ";
                    cin >> maBear;
                    bearList.XoaBear(maBear);
                    break;
                }
                case 8: {
                    string maBear;
                    cout << "Nhap ma bear can sua: ";
                    cin >> maBear;
                    bearList.SuaBear(maBear);
                    break;
                }
                case 9: bearList.writeFile("khohang.txt"); break;
                case 0: kt = false; break;
                default: cout << "Lua chon khong hop li, vui long chon lai.\n"; break;
            }
        }
    }
};
