// FOREACH method

/******************************
 * Syntax:
 *
 *
 * array.forEach((item, index, array) => {
    // item means the current item being iterated
    // index is the current item's index
    // array is the array being iterated. rarely used.
}, thisArg);



//* forEach example */


const app = document.querySelector(".menu-list");

const items = [
	{ id: 0, name: "Super Burger", price: 399 },
	{ id: 1, name: "Jumbo Fries", price: 199 },
	{ id: 2, name: "Big Slurp", price: 299 },
];

items.forEach(item => {
    app.innerHTML += `<li>ID: ${item.id} | item: ${item.name} | current price: ${item.price}</li>`
});


// MAP method

/******************************
 * Syntax:
 * returns a shallow copy
 * array.map((item, index, array) => {
    // item means the current item being iterated
    // index is the current item's index
    // array is the array being iterated. rarely used.
}, thisArg);

*/


const items = [
	{ id: 0, name: "Super Burger", price: 399 },
	{ id: 1, name: "Jumbo Fries", price: 199 },
	{ id: 2, name: "Big Slurp", price: 299 },
];

const halfJumbo = items.map(item => {
    if (item.name === 'Jumbo Fries') {
       return {
           ...item,
            price: parseInt((item.price / 2).toFixed(0), 10)
       };
    }
        return item;
});



// FILTER method

/******************************
 * Syntax:
 *
 * array.filter((item, index, array) => {
    // item means the current item being iterated
    // index is the current item's index
    // array is the array being iterated, rarely used.
}, thisArg);

*/

// filter example


const items = [
	{ id: 0, name: "Super Burger", price: 399 },
	{ id: 1, name: "Jumbo Fries", price: 199 },
	{ id: 2, name: "Big Slurp", price: 299 },
];

//filter and get all items with price above 200
const expensiveItems = items.filter(item => item.price > 300);
console.log(items);
console.log(expensiveItems);


// REDUCE method

/******************************
 * used to reduce the value of an array to a single value
 * Syntax:

 * array.reduce((prev, next, index, array) => {
    // item means the current item being iterated
    // index is the current item's index
    // array is the array being iterated, rarely used.
}, initialValue);

*/

// reduce example


const items = [
	{ id: 0, name: "Super Burger", price: 400 },
	{ id: 1, name: "Jumbo Fries", price: 200 },
	{ id: 2, name: "Big Slurp", price: 300 },
];

const totalPrice = items.map((item) => item.price).reduce((prev, next) => prev + next, 0);
console.log(totalPrice);



// EVERY method

/***********************
 * used to check if ALL element passes a test and returns a Boolean.
 * the loop terminates if any iteration evaluates to false or otherwise;
 * Syntax:

 * array.every((value, index, array) => {
    // item means the current item being iterated
    // index is the current item's index
    // array is the array being iterated, rarely used.
}, thisArg);

*/

// every example



const items = [
	{ id: 0, name: "Super Burger", price: 400 , promo: true},
	{ id: 1, name: "Jumbo Fries", price: 200 , promo: true},
	{ id: 2, name: "Big Slurp", price: 300 , promo: true},
];

const isInPromo = items.every((item) => item.promo);
console.log(isInPromo);

const total = isInPromo ? 600 : items.reduce((prev, next) => prev + next.price, 0);

console.log(total);




// SOME method

/***********************
 * used to check if any element passes a test and returns a Boolean.
 * the loop terminates if any iteration evaluates to true
 * Syntax:

 * array.some((value, index, array) => {
    // item means the current item being iterated
    // index is the current item's index
    // array is the array being iterated, rarely used.
}, thisArg);

*/

// some example



const items = [
	{ id: 0, name: "Super Burger", price: 400 , promo: false},
	{ id: 1, name: "Jumbo Fries", price: 200 , promo: false},
	{ id: 2, name: "Big Slurp", price: 300 , promo: true},
];

const isInPromo = items.some((item) => item.promo);
console.log(isInPromo);

const total = isInPromo ? 600 : items.reduce((prev, next) => prev + next.price, 0);

console.log(total);



// FIND method

/***********************
 *  find is used to find an element in an array  and returns the first occurance of that element.
 *
 * Syntax:

 * array.find((item, index, array) => {
    // item means the current item being iterated
    // index is the current item's index
    // array is the array being iterated, rarely used.
}, thisArg);

*/

// find example

const items = [
	{ id: 0, name: "Super Burger", price: 400, promo: false },
	{ id: 1, name: "Jumbo Fries", price: 200, promo: false },
	{ id: 2, name: "Big Slurp", price: 300, promo: true },
	{ id: 2, name: "Chicken Slurp", price: 300, promo: true },
	{ id: 2, name: "Big Jumbo", price: 200, promo: true },
];

const firstOccurance = items.find((item) => {
	return item.price === 300;
});

console.log(firstOccurance);
