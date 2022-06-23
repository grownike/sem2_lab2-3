#include <iostream>
#include "dynamic_array.h"
#include "sequence.h"
#include "array_sequnce.h"
#include "errors.h"
#include "linked_list.h"
#include "list_sequence.h"
#include "tests_array_sequence.h"
#include "tests_dynamic_array.h"
#include "tests_linked_list.h"
#include "tests_list_sequence.h"
#include "my_classes.h"
#include "IndexOutOfRange.h"
#include "tests_array_set.h"
#include "array_set.h"

void tests(){
    start_AS_tests();
    start_DA_tests();
    start_LL_tests();
    start_LS_tests();
    tests_array_set();
}

template<typename T>
void prints(ArraySet<T> to_print){
    for(int i = 0; i < to_print.GetSize(); i++){
        cout << to_print.GetElement(i) << " ";
    }
    cout << '\n';
}



int main() {
    tests();
    ArraySet<int> test5;

    for(int i = 0; i< 15; i++){
        test5.Append(i);
    }
    cout << "set: ";
    prints(test5);
    cout << "set where with bool(x) = 1 if x % 2 == 0: ";
    ArraySet<int> test6 = test5.Where([](int x){return (x % 2 == 0);});
    prints(test6);
    cout << "set map with f(x) = x * x: ";
    ArraySet<int> test7 = test5.Map([](int x){return (x * x);});
    prints(test7);
    cout << "set reduce with sum: ";
    int a = test5.Reduce([](int x){return x;});
    cout << a << "\n";

    try{
        int number;
        cin >> number;
        int test_number = test5.GetElement(number);
        cout << test_number << endl;
    }
    catch (IndexOutOfRange* e){
        cout << e->IndexErrorList(1) << endl;
        delete e;
    }

    try{
        int number;
        cin >> number;
        int test_number = test5.GetElement(number);
        cout << test_number << endl;
    }
    catch (IndexOutOfRange* e){
        cout << e->IndexErrorList(1) << endl;
        delete e;
    }
//    GEt_element(test5);
    cout << "Error handled\n";


    return 0;
}
