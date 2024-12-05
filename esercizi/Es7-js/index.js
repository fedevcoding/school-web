const table = document.querySelector("#table");

const persone = [
  { nome: "Mario", cognome: "Rossi", anni: 30 },
  { nome: "Giuseppe", cognome: "Verdi", anni: 40 },
  { nome: "Filippo", cognome: "Bianchi", anni: 35 },
  { nome: "Marta", cognome: "Neri", anni: 50 },
  { nome: "Federica", cognome: "Meucci", anni: 28 },
];

for (obj of persone) {
  const tr = document.createElement("tr");
  for (prop in obj) {
    const td = document.createElement("td");
    td.textContent = obj[prop];
    tr.appendChild(td);
  }
  table.appendChild(tr);
}
