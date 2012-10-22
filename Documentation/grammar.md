C: A Reference Manual, Fifth Edition
====================================

declaration:
    declaration-specifiers inititalized-declarator-list ;

declaration-specifiers:
    storage-class-specifier declaration-specifiers
    type-specifier declaration-specifiers
    type-qualifier declaration-specifiers
    function-specifier declaration-specifiers

initialized-declarator-list:
    initialized-declarator
    initialized-declarator-list , inititalized-declarator

initialized-declarator:
    declarator
    declarator = initializer

storage-class-specifier: one of
    auto extern register static typedef

function-specifier:
    inline

type-specifier:
    enumeration-type-specifier
    floating-point-type-specifier
    integer-type-specifier
    structure-type-specifier
    typedef-name
    union-type-specifier
    void-type-specifier

type-qualifier:
    const
    volatile
    restrict

declarator:
    pointer-declarator
    direct-declarator

direct-declarator:
    simple-declarator
    ( declarator )
    function-declarator
    array-declarator

simple-declarator:
    identifier

pointer-declarator:
    pointer direct-declarator

pointer:
    * type-qualifier-list
    * type-qualifier-list pointer

type-qualifier-list:
    type-qualifier
    type-qualifier-list type-qualifier


