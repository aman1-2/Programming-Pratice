function Product(n, p, d) {
    this.name = n;
    this.price = p;
    this.description = d;

    this.display = function printDetails() { console.log(this); }

    console.log(this);
}

const p = Product("Bag", 100, "School Bag");
console.log(p);
console.log(globalThis);