#include <iostream>
#include <memory>

class Node {
public:
    Node() = delete;
    Node(int data) : data_(data) {} 
    int data_;
    std::unique_ptr<Node> left_;
    std::unique_ptr<Node> right_;
};

class BinarySearchTree {
public:
    BinarySearchTree() = delete;
    BinarySearchTree(int data) {
        head_ = std::make_unique<Node>(data);
    }
    void AddNode(int data) {
        Node* crn_node = head_.get(); // 최선?
        Node* pre_node = nullptr;

        while(crn_node != nullptr) { 
            pre_node = crn_node;
            if(crn_node->data_ > data) {
                crn_node = crn_node->left_.get();
            }
            else {
                crn_node = crn_node->right_.get();
            }
        }
        if(pre_node->data_ > data) {
            pre_node->left_ = std::make_unique<Node>(data);
        }
        else {
            pre_node->right_ = std::make_unique<Node>(data);
        }   
    }

    bool SearchNode(int target) {
        Node* crn_node = head_.get();
        while(crn_node != nullptr) {
            if(crn_node->data_ == target) {
                return 1;
            }
            if(crn_node->data_ > target) {
                crn_node = crn_node->left_.get();
            }
            else {
                crn_node = crn_node->right_.get();
            }
        }
        return 0;
    }

    // leaf 일때) 그냥 삭제
    // leaf가 아닐때) 
    void DeleteNode(int target) {
        DeleteNode(target, head_.get());
    }
    void DeleteNode(int target, Node* node) {
        Node* crn_node = node;
        Node* pre_node = nullptr;

        // 타겟을 찾아
        while(crn_node != nullptr) {
            if(crn_node->data_ == target) {
                break;
            }
            pre_node = crn_node;
            if(crn_node->data_ > target) {
                crn_node = crn_node->left_.get();
            }
            else {
                crn_node = crn_node->right_.get();
            }
        }
        //자식이 없을 때
        if(crn_node->left_ == nullptr && crn_node->right_ == nullptr) {
                if(pre_node->left_ != nullptr) {
                    if(pre_node->left_->data_ == target) {
                        pre_node->left_ = nullptr;
                        return;
                    }
                }
                pre_node->right_ = nullptr;
        }

        //타겟 노드의 자식이 있을때
        else {
            Node* temp_node = crn_node;
            pre_node = crn_node;
            // 왼쪽 자식이 있을 때
            if(crn_node->left_ != nullptr) {
                crn_node = crn_node->left_.get();
                // 자기가 최고 클때
                if(crn_node->right_ == nullptr) {
                    temp_node->data_ = crn_node->data_;
                    if(crn_node->left_ == nullptr  && crn_node->right_ == nullptr)
                        temp_node->left_ = nullptr;
                    else
                        DeleteNode(crn_node->data_, crn_node);
                    return;
                }
                // 자기보다 더 큰 노드가 있을 때
                while(crn_node->right_ != nullptr) {
                    temp_node = crn_node;
                    crn_node = crn_node->right_.get();
                }
                pre_node->data_= crn_node->data_;
                if(crn_node->left_ == nullptr  && crn_node->right_ == nullptr)
                    temp_node->right_= nullptr;
                else
                    DeleteNode(crn_node->data_, crn_node);
            }
            // 오른쪽 자식이 있을 때
            else {
                crn_node = crn_node->right_.get();
                // 자기가 최고 작을 때
                if(crn_node->left_ == nullptr) {
                    temp_node->data_ = crn_node->data_;
                    if(crn_node->left_ == nullptr  && crn_node->right_ == nullptr)
                        temp_node->right_ = nullptr;
                    else
                        DeleteNode(crn_node->data_, crn_node);
                    return;
                } 
                // 자기보다 작은 노드가 있을 때
                while(crn_node->left_ != nullptr) {
                    temp_node = crn_node;
                    crn_node = crn_node->left_.get();
                }
                pre_node->data_= crn_node->data_;
                if(crn_node->left_ == nullptr  && crn_node->right_ == nullptr)
                    temp_node->left_ = nullptr;
                else
                    DeleteNode(crn_node->data_, crn_node);
            }
        }
    }

    void print() {
        inorder(head_.get());
    }

    void inorder(Node* node) {
        if(node == nullptr)
            return;
        
        inorder(node->left_.get());
        std::cout << node->data_ << " ";
        inorder(node->right_.get());
    }

private:
    std::unique_ptr<Node> head_;    
};