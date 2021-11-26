#include <stdio.h>
#include <stdlib.h>

typedef struct btree_t
{
    int order;
    node_t *root;

} BTree;

BTree *btree_new(int order)
{
    BTree *bt = malloc(sizeof(BTree));
    assert(bt != NULL);

#if DEBUG
    printf("allocated new b-tree of order %d\n", order);
#endif

    // Após alocar, temos que inicializar a B-Tree
    btree_init(bt, order);

    return bt;
}

void btree_init(BTree *bt, int order)
{
    assert(bt != NULL);

    bt->order = order;
    bt->root = _node_new(order, TRUE);
}

node_position btree_find(BTree *bt, int key)
{
    assert(bt != NULL);

#if DEBUG
    printf("calling _btree_find_node() over key: %d\n", key);
#endif

    return _btree_find_node(bt->root, key);
}

node_position _btree_find_node(node_t *node, int key)
{
    assert(node != NULL);

    int pos;
    if (_node_find_key(node, key, &pos))
    {
        // Se a chave foi encontrada nesse nó,
        // retorne um meio de acessá-la
        return _node_position_new(node, pos);
    }
    else
    {
        // Se a chave não foi encontrada
        if (node->is_leaf)
        {
            // e o nó atual é uma folha,
            // então key não pertence à B-Tree
            return _node_position_new(NULL, -1);
        }
        else
        {
            // e o nó atual possui filhos,
            // então devemos explor o filho na posição pos
            return _btree_find_node(node->children[pos], key);
        }
    }
}

node_position btree_insert(BTree *bt, int key, void *value)
{
    assert(bt != NULL);

#if DEBUG
    printf("inserting key %d\n", key);
#endif

    node_t *root = bt->root;

    // Esse pair será enviado durante as chamadas recursivas de inserção,
    // e é o que realmente será inserido na B-Tree
    pair_t *pair = _pair_new(key, value);

    if (root->n_keys == 2 * bt->order - 1)
    {
        // Caso a raiz da B-Tree já esteja cheia,
        // devemos executar o procedimento de split
        // e deixá-la com apenas uma chave.
        // Esse é o único caso em que a altura da B-Tree aumenta

#if DEBUG
        printf("root full - spliting up\n");
#endif

        node_t *new_root = _node_new(bt->order, FALSE);
        new_root->children[0] = root;

        _btree_split(new_root, 0, bt->order);
        bt->root = new_root;

        // Podemos prosseguir com a inserção
        return _btree_insert_nonfull(new_root, pair, bt->order);
    }
    else
    {
// A raiz respeita a restrição de não estar cheia
#if DEBUG
        printf("root not full - calling _btree_insert_nonfull()\n");
#endif

        return _btree_insert_nonfull(root, pair, bt->order);
    }
}

void _btree_split(node_t *node, int pos, int order)
{
    // Para mais informações, consulte a documentação,
    // em especial o pseudo-código B-Tree-Split-Child

    node_t *y = node->children[pos];
    assert(y != NULL);

    node_t *z = _node_new(order, y->is_leaf);
    z->n_keys = order - 1;

#if DEBUG
    printf("moving keys from root to right: ");
#endif
    _node_deslocate_keys_up(z, y, 0, order - 1, 0, order);

    if (!y->is_leaf)
    {
#if DEBUG
        printf("moving children from root to right: ");
#endif
        _node_deslocate_children_up(z, y, 0, order, 0, order);
    }
    y->n_keys = order - 1;

#if DEBUG
    printf("deslocating new-root childrens pos: ");
#endif
    _node_deslocate_children_down(node, node, node->n_keys, pos, 1, 0);

    node->children[pos + 1] = z;

#if DEBUG
    printf("moving %d keys: ", node->n_keys);
#endif
    _node_deslocate_keys_down(node, node, node->n_keys - 1, pos - 1, 1, 0);

#if DEBUG
    printf("inserting key %d at %d of new-root\n", y->keys[order - 1]->key, pos);
#endif
    node->keys[pos] = y->keys[order - 1];

    node->n_keys++;
}

int main()
{

}