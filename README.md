This project tests the linking behavior regarding symbol export.

`lib_foo` contains two obj files `foo` and `foo1`, each of which defines a
linked-list node, `foo_node` and `foo1_node` respectively, that are linked at
static initialization time.

`shared_lib_bar` is a shared library that also defines a linked-list node
`bar_node`, of the same base type as `foo_node` and `foo1_node`.
`shared_lib_bar` is linked against `lib_foo`. If all symbols from `lib_foo` are
imported into `shared_lib_bar`, all three linked-list nodes will be linked.

However, that's not how linking works. From what I observed, a symbol is
imported if any of the symbols in the same object file is referenced by the
dependent lib. For example, if a symbol `A` from foo.obj is referenced by
`shared_lib_bar`, then `foo_node`, along with all other symbols in foo.obj, is
also imported into `shared_lib_bar`. Note, even though `lib_foo` contains both
foo.obj and foo1.obj, symbol `A` is defined in foo.obj, not foo1.obj, therefore
`foo1_node` will not be imported.
