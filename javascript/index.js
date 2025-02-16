// 
// alert("hello world from js")
// vaariable declare using var keyword
var firstName= "Sangam";
var firstName= "Gopal";//re_declare

console.log(firstName, "FirstName");


 function printfullName()
{
    var lastName = "Mishra"
    console.log(firstName+ " "  +lastName, "FullName inside");//log the fulltname
}

printfullName();
// console.log(lastName, "lastName")

// // vaariable declare using let keyword
let fruit= "Apple";
fruit = "Banana";

console.log(fruit, "fruit");

const  book= "Math";

console.log(book, "book");
{
    var color = "green";//let and conts are block scope
    // var is function scope
    //hoisting 
}
console.log(color, "color");



  let isValid = true;//boolean
  let isSelected = null; //null
  let greet;
  //var is decalared and value is not assinged so it will return undefine.
  console.log(greet, "greet greet");

  let x = 10;
  let y= 5;
let z= x + y;
console.log(z, "sum");