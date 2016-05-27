#ifndef __SKIPLIST_H
#define __SKIPLIST_H

#include <vector>

const int SKIPLIST_MAXLEVEL  = 8;

// 跳表节点
struct SkiplistNode{

    SkiplistNode(int level, double score);

    double score_;
    SkiplistNode* backward_;
    std::vector<SkiplistNode*> levels_;
};

// 跳表定义
class Skiplist{
    private:
        SkiplistNode *header_, *tail_;
        unsigned long length_;
        int level_;

    public:
        Skiplist();
        ~Skiplist();

        // 插入一个节点
        SkiplistNode* insert(double score);

        // 删除一个节点
        int deleteItem(double score);

        // 查找一个节点
        int search(double score);
        
        // 答应跳表
        void print();

    private:
        // 辅助函数：产生随机的层数 
        int generateRandomLevel();

        // 辅助函数：删除一个跳表节点
        void deleteNode(SkiplistNode* x, SkiplistNode** update);
};
#endif
