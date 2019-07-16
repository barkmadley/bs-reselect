type item = {
  name: string,
  value: float,
};
type shop = {
  taxPercent: float,
  items: array(item),
};
type state = {shop};

let shopItemsSelector = (. state) => state.shop.items;
let taxPercentSelector = (. state) => state.shop.taxPercent;

let subtotalSelector =
  Reselect.create1(shopItemsSelector, (. items) =>
    Array.fold_left((acc, item) => acc +. item.value, 0.0, items)
  );

let taxSelector =
  Reselect.create2(
    subtotalSelector, taxPercentSelector, (. subtotal, taxPercent) =>
    subtotal *. (taxPercent /. 100.0)
  );

type total = {total: float};

let totalSelector =
  Reselect.create2(subtotalSelector, taxSelector, (. subtotal, tax) =>
    {total: subtotal +. tax}
  );

let exampleState = {
  shop: {
    taxPercent: 8.0,
    items: [|{name: "apple", value: 1.20}, {name: "orange", value: 0.95}|],
  },
};

Js.log(subtotalSelector(. exampleState)); // 2.15
Js.log(taxSelector(. exampleState)); // 0.172
Js.log(totalSelector(. exampleState)); // { total: 2.322 }
