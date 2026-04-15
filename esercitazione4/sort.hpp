#include <optional>
/*Implementazione funzione is_sorted */
template<typename T> 
bool is_sorted(const std::vector<T>& vec) {
    if (vec.size()==0) {
        return true;
    }
    for (int i =1; i<vec.size(); i++) {
        if (vec[i]<vec[i-1]) {
            return false;
        }
    }
    return true; 
    
}
/*Implementazione dell'algoritmo Bubble-sort*/
template <typename T>
void bubble_sort (std::vector<T>& vec) {
    for (int i=0 ; i < vec.size()-1 ;i++) {
        for (int j= vec.size()-1; j > i ; j--) {
            if (vec[j]<vec[j-1]) {
                std::swap(vec[j],vec[j-1]);
            }
        }
    }
}
/*Implementazione dell'algoritmo Insertion-sort*/
template <typename T>
void insertion_sort (std::vector<T>& vec) {
    for (int j = 1; j< vec.size(); j++) {
        T key = vec[j];
        int i = j-1;
        while ( i>=0 && vec[i]>key) {
            vec[i+1]=vec[i];
            i= i-1;
        }
        vec[i+1]=key;
    }
}
/*Implementazione dell'algoritmo Selection-sort*/
template <typename T>
void selection_sort (std::vector<T>& vec) {
    for (int i = 0; i< vec.size(); i++) {
        int min =i ;
        for(int j = i+1; j < vec.size() ; j++ ) {
            if (vec[j]<vec[min]) {
                min = j;
            }
        }
        std::swap(vec[i], vec[min]);
    }
}