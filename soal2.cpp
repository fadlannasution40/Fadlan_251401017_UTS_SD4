// SINGLE LINKED LIST CIRCULAR
// Sama seperti single linked list, tapi node terakhir menunjuk balik ke head.
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

int main() {
    Node *head = nullptr;
    int pilihan, x;

    do {
        cout << "\n=== SINGLE LINKED LIST CIRCULAR ===" << endl;
        cout << "1. Tambah depan" << endl;
        cout << "2. Tambah belakang" << endl;
        cout << "3. Hapus depan" << endl;
        cout << "4. Hapus belakang" << endl;
        cout << "5. Hapus berdasarkan nilai" << endl;
        cout << "6. Cari data" << endl;
        cout << "7. Tampilkan" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1: {
            cout << "Masukkan data: ";
            cin >> x;
            Node *baru = new Node;
            baru->data = x;
            if (head == nullptr) {
                baru->next = baru; 
                head = baru;
            } else {
                Node *ekor = head;
                while (ekor->next != head) { 
                    ekor = ekor->next;
                }
                baru->next = head;
                ekor->next = baru; 
                head = baru;
            }
            cout << "Data " << x << " ditambah di depan." << endl;
            break;
        }
        case 2: {
            cout << "Masukkan data: ";
            cin >> x;
            Node *baru = new Node;
            baru->data = x;
            if (head == nullptr) {
                baru->next = baru;
                head = baru;
            } else {
                Node *ekor = head;
                while (ekor->next != head) {
                    ekor = ekor->next;
                }
                ekor->next = baru;
                baru->next = head;  
            }
            cout << "Data " << x << " ditambah di belakang." << endl;
            break;
        }
        case 3: {
            if (head == nullptr) {
                cout << "List kosong." << endl;
            } else if (head->next == head) {  
                cout << "Data " << head->data << " dihapus." << endl;
                delete head;
                head = nullptr;
            } else {
                Node *ekor = head;
                while (ekor->next != head) {
                    ekor = ekor->next;
                }
                Node *hapus = head;
                head = head->next;
                ekor->next = head;  
                cout << "Data " << hapus->data << " dihapus." << endl;
                delete hapus;
            }
            break;
        }
        case 4: {
            if (head == nullptr) {
                cout << "List kosong." << endl;
            } else if (head->next == head) {
                cout << "Data " << head->data << " dihapus." << endl;
                delete head;
                head = nullptr;
            } else {
                Node *bantu = head;
                while (bantu->next->next != head) {  
                    bantu = bantu->next;
                }
                cout << "Data " << bantu->next->data << " dihapus." << endl;
                delete bantu->next;
                bantu->next = head;
            }
            break;
        }
        case 5: {
            cout << "Masukkan data yang dihapus: ";
            cin >> x;
            if (head == nullptr) {
                cout << "List kosong." << endl;
            } else if (head->data == x) {  
                if (head->next == head) {
                    delete head;
                    head = nullptr;
                } else {
                    Node *ekor = head;
                    while (ekor->next != head) {
                        ekor = ekor->next;
                    }
                    Node *hapus = head;
                    head = head->next;
                    ekor->next = head;
                    delete hapus;
                }
                cout << "Data " << x << " dihapus." << endl;
            } else {
                Node *bantu = head;
                while (bantu->next != head && bantu->next->data != x) {
                    bantu = bantu->next;
                }
                if (bantu->next == head) {
                    cout << "Data " << x << " tidak ditemukan." << endl;
                } else {
                    Node *hapus = bantu->next;
                    bantu->next = hapus->next;
                    delete hapus;
                    cout << "Data " << x << " dihapus." << endl;
                }
            }
            break;
        }
        case 6: {
            cout << "Masukkan data yang dicari: ";
            cin >> x;
            if (head == nullptr) {
                cout << "List kosong." << endl;
            } else {
                Node *bantu = head;
                int posisi = 1;
                bool ketemu = false;
                do {
                    if (bantu->data == x) {
                        cout << "Data " << x << " ditemukan di posisi ke-" << posisi << endl;
                        ketemu = true;
                        break;
                    }
                    bantu = bantu->next;
                    posisi++;
                } while (bantu != head);  
                if (!ketemu) {
                    cout << "Data " << x << " tidak ditemukan." << endl;
                }
            }
            break;
        }
        case 7: {
            if (head == nullptr) {
                cout << "List kosong." << endl;
            } else {
                Node *bantu = head;
                do {
                    cout << bantu->data << " -> ";
                    bantu = bantu->next;
                } while (bantu != head);
                cout << "(kembali ke head)" << endl;
            }
            break;
        }
        case 0:
            cout << "Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    if (head != nullptr) {
        Node *ekor = head;
        while (ekor->next != head) {
            ekor = ekor->next;
        }
        ekor->next = nullptr;
        while (head != nullptr) {
            Node *hapus = head;
            head = head->next;
            delete hapus;
        }
    }
    return 0;
}
