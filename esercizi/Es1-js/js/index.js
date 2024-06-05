const buy = () => {

    let age;

    while (!age || age < 0) {
        age = parseInt(prompt("Inserisci la tua eta"));
    }

    let price = 8;

    if (age < 5) {
        price = 0;
    }
    else if (age >= 18 && age <= 25) {
        price = 3.3;
    } else if (age >= 50 && age <= 55) {
        price = 5;
    }

    console.log(`${age} anni - paghi ${price} euro`)
    alert(`${age} anni - paghi ${price} euro`)
}