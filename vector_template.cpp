#include<iostream>
#include<string>
#include<vector>
#include <iomanip>

/*
Name: Ryan Avancena
CWID: 885367821

*/

template <typename T> class Item{
    public:
        T name;
        T expiration;
        T category;
        int quantity;
        Item(T n, T e, T c, int q){
            name = n;
            expiration = e;
            category = c;
            quantity = q;
        }
};
template<typename T> class Inventory{
    public:
        void addNewItem(Item<T> _item) {
            bool condition = false; 
            /* ITERATES THROUGH LIST OF ITEMS */
            for (int i = 0; i < items.size();i++) {
                if (items[i].name == _item.name) {
                    std::cout<<"Item is already present in inventory."<<std::endl;
                    condition = true;
                    break;
                }
            }
            if (!condition) {
                this->items.push_back(_item);
            }
        }

        void updateItem(T _itemName, T _expiration, T _category, int _quantity) {
            /* ITERATES THROUGH LIST OF ITEMS */
            bool condition = false; 
            for (int i = 0; i < items.size();i++) {
                if (items[i].name == _itemName) {
                    items[i].expiration = _expiration;
                    items[i].category = _category;
                    items[i].quantity = _quantity;
                    condition = true;
                    break;
                }
            }
            if (!condition) {
                throw "Item not found in inventory. (updateItem) ";
            }
        }

        void increaseQuantity(T _itemName, int _quantity) {
            /* ITERATES THROUGH LIST OF ITEMS */
            bool condition = false; 
            for (int i = 0; i < items.size();i++) {
                if (items[i].name == _itemName) {
                    items[i].quantity = _quantity;
                    condition = true;
                    break;
                }
            }
            if (!condition) {
                throw "Item not found in inventory. (increaseQuantity) ";
            }
        }

        void Total() {
            int total = 0;
            for (int i = 0; i < items.size(); i++) {
                total++;
            }
            std::cout << "You have " << total << " items in your inventory. (Total)" << std::endl; 
        }
        
        void removeItem(T _itemName) {
            for (int i = 0; i < items.size();i++) {
                if (items[i].name == _itemName) {
                    items.erase(items.begin() + i);
                    return;
                }
            }
            throw "Item not found in inventory. (Remove)";
        }
        
        void searchItem(T _itemName) {
            for (int i = 0; i < items.size();i++) {
                if (items[i].name == _itemName) {
                    std::cout << _itemName << " found in inventory. (Search)" << std::endl; 
                    std::cout<<"-------Item-------"<<std::endl;
                    std::cout<<std::left << std::setw(20)<<items[i].name<<std::setw(15)<<items[i].expiration<<std::setw(15)<<items[i].quantity<<std::setw(15)<<items[i].category<<std::endl;
                    return;
                }
            }
            throw "Item not found in inventory. (Search)";
        }
        
        std::vector<Item<T>>items;

        void displayItems(){
            std::cout<<"-------Inventory-------"<<std::endl;
            std::cout<<std::left<<std::setw(20)<<"Name"<<std::setw(15)<<"Expiration"<<std::setw(15)<<"Category"<<std::setw(10)<<"Quantity"<<std::endl;
            for(int i=0; i<items.size();i++){
                std::cout<<std::left << std::setw(20)<<items[i].name<<std::setw(15)<<items[i].expiration<<std::setw(15)<<items[i].quantity<<std::setw(15)<<items[i].category<<std::endl;
            }
        }


};

template<typename T>class Appointment{
    public: 
        T c_name;
        T ap_date;
        T ap_time;
        T CWID;
        Appointment(T n, T d, T t, T cw){
            c_name = n;
            ap_date = d;
            ap_time = t;
            CWID = cw; 
        }
};

template<typename T>class AppointmentSystem{
        public:
        void schedule(Appointment<T> _appointment) {
            bool condition = false; 
            /* ITERATES THROUGH LIST OF ITEMS */
            for (int i = 0; i < ap.size();i++) {
                if (_appointment.CWID == ap[i].CWID) {
                    std::cout<< "You have already scheduled an appointment."<<std::endl;
                    condition = true;
                    break;
                }
            }
            if (!condition) {
                this->ap.push_back(_appointment);
            }
        }

        void Total_appointments(T _ap_date, T _ap_time) {
            int total = 0;
            for (int i = 0; i < ap.size(); i++) {
                if (_ap_date == ap[i].ap_date && _ap_time == ap[i].ap_time) {
                    total++;
                }
            }
            std::cout << "There are " << total << " appointments on " << _ap_date <<" at " << _ap_time << "." << std::endl; 
        }

        void removeRecent() {
            int indexRemove = ap.size() - 1;
            this->ap.erase(ap.begin() + indexRemove);
        }

        std::vector<Appointment<T>> ap;

        void display(){
            std::cout<<"-------Appointments-------"<<std::endl;
            std::cout<<std::left<<std::setw(20)<<"Name"<<std::setw(15)<<"Date"<<std::setw(15)<<"Time"<<std::setw(15)<<"CWID"<<std::endl;
            for(int i=0; i<ap.size();i++){
                std::cout<<std::left << std::setw(20)<<ap[i].c_name<<std::setw(15)<<ap[i].ap_date<<std::setw(15)<<ap[i].ap_time<<std::setw(15)<<ap[i].CWID<<std::endl;
            }
        }
};

int main(){
    Inventory<std::string> i1;
    Item<std::string> I1("Protien Bar","05/09/2023","Snacks",4);
    i1.addNewItem(I1);
    Item<std::string> I2("Milk","05/12/2023","Regular",2);
    i1.addNewItem(I2);
    Item<std::string> I3("Cerels","09/12/2023","Snacks",5);
    i1.addNewItem(I3);
    i1.displayItems();
    i1.updateItem("Milk","09/24/2023","Regular",3);
    i1.displayItems();
    i1.increaseQuantity("Cerels",10);
    i1.displayItems();
    try{
        i1.updateItem("bar","09/12/2023","Snacks",3);
    }
    catch(const char* msg){
        std::cout <<msg << std::endl;
    }
    i1.displayItems();
    i1.updateItem("Cerels","09/27/2023","Regular",4);
    i1.displayItems();
    i1.Total();
    try{
        i1.removeItem("Bread");
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    try{
        i1.removeItem("Milk");
    }
    catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    i1.displayItems();
    try{
        i1.searchItem("Cerels");
    }
        catch(const char* msg){
        std::cout<<msg<<std::endl;
    }
    Appointment<std::string> a1("John Bob","09/12/2023","9:30AM","889456723");
    Appointment<std::string> a2("Jim Lee","09/12/2023","10:30AM","883476923");
    Appointment<std::string> a3("Chris Lynn","09/12/2023","12:00PM","879455714");
    Appointment<std::string> a4("Arnav Shah","09/12/2023","12:00PM","879459583");
    AppointmentSystem<std::string> s1;
    s1.schedule(a1);
    s1.schedule(a2);
    s1.schedule(a3);
    s1.schedule(a4);
    s1.display();
    s1.Total_appointments("09/12/2023","12:00PM");
    Appointment<std::string> a5("Chris Lynn","09/12/2023","12:00PM","879455714");
    s1.schedule(a5);
    s1.removeRecent();
    s1.display();
}
