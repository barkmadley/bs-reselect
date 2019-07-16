# bs-reselect

Low-level bindings to [reselect](https://github.com/reduxjs/reselect) for [BuckleScript](https://github.com/bucklescript/bucklescript).

[![npm](https://img.shields.io/npm/v/bs-reselect.svg)](https://npmjs.org/bs-reselect)
[![Issues](https://img.shields.io/github/issues/barkmadley/bs-reselect.svg)](https://github.com/barkmadley/bs-reselect/issues)
[![Last Commit](https://img.shields.io/github/last-commit/barkmadley/bs-reselect.svg)]()

`bs-reselect` is intended as a direct binding to the JS API. It is purely a way to use the reselect library, and since the module comprises entirely of external declarations, there is no runtime/code size overhead from using these bindings.

## Example

```reason
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
```

## Installation

```sh
npm install --save bs-reselect
```

Then add `bs-reselect` to `bs-dependencies` in your `bsconfig.json`:

```js
{
  ...
  "bs-dependencies": ["bs-reselect"]
}
```

## Usage

See usage examples in [`readme.re`](https://github.com/barkmadley/bs-reselect/blob/master/examples/readme.re). The source is a [single file](https://github.com/barkmadley/bs-reselect/blob/master/src/Reselect.re) that corresponds almost directly to the [typescript bindings](https://github.com/reduxjs/reselect/blob/master/src/index.d.ts#L19).

## Changes

### 0.1.0

- Initial release with bindings for up to 9 createSelector parameters
