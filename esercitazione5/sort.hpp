#include <optional>
#include <limits>

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

/*Implementazione dell'algoritmo Quicksort*/

template <typename T>
int partition (std::vector<T> & vec, int p , int r) {
    T x=vec[r];
    int i=p-1;
    for (int j = p; j<r ; j++ ) {
        if(vec[j]<=x) {
            i=i+1;
            std::swap(vec[i],vec[j]);
        }
    }
    std::swap(vec[i+1],vec[r]);
    return i+1;
}

template <typename T>
void quick_sort (std::vector<T> & vec, int p, int r ) {
    if (p<r) {
        int q =partition(vec ,p,r );
        quick_sort(vec, p, q-1);
        quick_sort(vec, q+1,r);
    }
}

/*Implementazione dell'algoritmo Mergesort*/
template <typename T> 
void merge (std::vector<T> & vec, int p, int q, int r, const T & INF){
    int n1= q-p+1;
    int n2= r-q;
    std::vector<T> L(n1+1);
    std::vector<T> R(n2+1);

    for (int i = 0 ; i<n1 ; i++) {
        L[i] =vec[p+i];
    }
    for (int j = 0 ; j<n2 ; j++) {
        R[j] = vec[q+1+j];
    }
    L[n1] = INF;
    R[n2] = INF;

    int i=0;
    int j=0 ;
    for (int k = p ; k<=r ; k++) {
        if (L[i]<= R[j]) {
            vec[k] = L[i];
            i=i+1;
        }
        else {
            vec[k] = R[j];
            j=j+1;
        }
    }
}

template <typename T> 
void merge_sort_impl (std::vector<T> & vec,int p,int r, const T & INF) {
    if ( p < r ) {
        int q = (p+r)/2;
        merge_sort_impl(vec, p, q, INF);
        merge_sort_impl(vec, q+1,r , INF);
        merge(vec,p,q,r, INF);
    }
}

template <typename T> 
void merge_sort(std::vector<T> & vec, int p, int r) {
    if (vec.empty()) return;
    T INF = std::numeric_limits<T>::max();
    merge_sort_impl(vec, p , r, INF);
}

template <>
void merge_sort(std::vector<std::string> & vec, int p, int r) {
    if (vec.empty()) return;
    std::string INF(300, 'z');
    merge_sort_impl(vec, p , r, INF);
}

/*Implementazione Quicksort modificato*/
template <typename T>
void quick_sort_mod (std::vector<T> & vec, int p, int r , int soglia) {
    if (p<r) {
        if (r - p +1 <= soglia) {
            std::vector<T> portion(vec.begin()+p, vec.begin()+r+1);
            insertion_sort(portion);
            for (int i = 0; i < (int)portion.size(); i++)
                vec[p+i] = portion[i];
        } else {
            int q = partition(vec, p, r);
            quick_sort_mod(vec, p, q-1, soglia);
            quick_sort_mod(vec, q+1, r, soglia);
        }
    }
}
 template <typename T>
 void quick_sort_mod(std::vector<T> & vec, int soglia =50) {
    quick_sort_mod(vec, 0, vec.size()-1, soglia);
 }