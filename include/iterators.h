#include<utility> //pair
#include<memory>

template <typename k_t, typename v_t, typename OP> 
template <typename O> 
class bst<k_t, v_t, OP>::_iterator {
  using node = typename bst<k_t,v_t,OP>::node;
  node* current;
  
public:
  OP op;
  using pair_type = O;
  //using value_type = O;
  //using pair_type = std::pair<k_t,O>;
  using reference = pair_type &;
  using pointer = pair_type *;
  using difference_type = std::ptrdiff_t;
  using iterator_category = std::forward_iterator_tag;


  //constructor

  explicit _iterator(node *p): current{p} {} 

  reference operator*() const { return current->pair; }
  pointer operator->() const { return &**this; }

  node* getcurrent() {return current;}
  // pre-increment
  _iterator &operator++() {
   if (current != nullptr){
     
   if (current->right.get() != NULL)
   {
      current = current->right.get();

      while (current->left.get() != NULL){
      
      current = current->left.get();}
       }
    else{
        node* tmp = current->parent;

        while(tmp && current != tmp->left.get()){
            current = tmp;
            tmp = tmp->parent;
        }

        current = tmp;
    

    }
    }

    return *this;
    
  }
  _iterator operator++(int) {
  auto tmp{*this};
  ++(*this);
  return tmp;
  }

  friend bool operator==(_iterator &a, _iterator &b) {
    return a.current == b.current;
  }

  friend bool operator!=(_iterator &a, _iterator &b) { return !(a == b); }
};