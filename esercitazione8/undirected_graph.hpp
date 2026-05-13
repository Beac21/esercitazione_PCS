#include <iostream> 
#include <numeric>
#include <set>
#include <map>


template <typename I>
    requires std::integral<I> 
class undirected_edge {
    I node1_;
    I node2_;

public: 
    /*Costruttore di deafult*/
    undirected_edge()
        : node1_(0), node2_(1)
    {}
    /*Restituisce nodo partenza e nodo arrivo*/
    I from () const {return node1_;}
    I to () const {return node2_;}

    undirected_edge (I a, I b) 
        :node1_(a), node2_(b)
        {if (a>b) std::swap(node1_,node2_);}


    /*Implementazione operatori*/
    //per ordinare archi
    bool operator< (const undirected_edge & other) const{
        if (node1_< other.node1_) return true;
        if (node1_ > other.node1_ ) return false;
        else {
            if (node2_ < other.node2_) return true;
            else return false;
        }
     
    }

    //Nodi uguali
    bool operator==  (const undirected_edge & other) const{
        if (node1_ == other.node1_ && node2_==other.node2_) return true; 
        else return false;
        
    }
    

};

//stampa dell'oggetto
template <typename I> 
std::ostream& operator<< (std::ostream& os, const undirected_edge<I>& e) {
   os << "(" <<  e.from() <<","<<e.to() << ")" ;
   return os;
}


template <typename I>
    requires std::integral<I> 
class undirected_graph {
    
    std::map<I, std::set<I>> adjacency_;
    std::set<undirected_edge<I>> edges_;
    public: 
    /*Costruttore di deafult*/
    undirected_graph() {}

    /*Costruttore di copia*/
    undirected_graph(const undirected_graph<I> & other)
        : adjacency_(other.adjacency_), edges_(other.edges_)
    {}

    /*Implementazione operatori*/
    
    void  add_edge(const undirected_edge<I> & e) {
        edges_.insert(e);
        adjacency_[e.from()].insert(e.to());
        adjacency_[e.to()].insert(e.from());

    }

    std::set<I> neighbours(I n) {
        return adjacency_[n];
    }
    /*Restituisce tutti gli archi*/
    std::set<undirected_edge<I>> all_edges() {
        return edges_;
    }

    /*Restituisce tutti i nodi*/
    std::map<I, std::set<I>> all_nodes() {
        return adjacency_;
    }
    /*Dato un arco ne restituisce la posizione corrispondente*/
    int edge_number(const undirected_edge<I> & e) {
        int count = 0;
        for (const auto & edge : edges_) {
            if (edge == e) return count; 
            count++;
        }
        return -1;
        }
    /*Dato un numero ne restituisce l'arco corrispondente*/
    undirected_edge<I> edge_at (int n) {
        int count = 0; 
        for (const auto & edge : edges_ ) {
            if ( count == n ) return edge;
            else count++;
        }
        return undirected_edge<I>();
    }

    undirected_graph<I> operator- (const undirected_graph<I> & other) const {
        undirected_graph<I> result;
        for (const auto & edge : edges_) {
            if (other.edges_.count(edge)==0) 
                result.add_edge(edge);
        }
        return result;
    }

    };