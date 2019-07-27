/**
  Use these phantom types to ensure that the Curry constructor is only applied
  with a RHS of Select. This ensures that we have a reverse linked list
  structure such as:
    Curry(Curry(Select, Select), Select)
  And we exclude structures like:
    Curry(Curry(Select, Select), Curry(Select, Select))
    and
    Curry(Select, Curry(Select, Select))
 */
type curry;
type select;

type t(_, _, _, _) =
  | Curry(
      t('either, 'input, 'processor2, 'processor1),
      t(select, 'input, 'output2, 'processor2),
    )
    : t(curry, 'input, 'output2, 'processor1)
  | Select((. 'input) => 'output1)
    : t(select, 'input, 'output, 'output1 => 'output);

let (=>>) = (a, b) => Curry(a, b);

let select = stateToValue => Select(stateToValue);
let curry = (=>>);

/**
  These phantom types allow us to call the JS reselect API by "casting" the
  given selectors and callbacks into the right types
 */
type callback;
type selector;

[@bs.module "reselect"]
external createSelector: (array(selector), callback) => (. 'state) => 'output =
  "createSelector";

external castSelector: 'a => selector = "%identity";
external castCallback: 'a => callback = "%identity";

let rec countSelectors:
  type constructor input output processor.
    (t(constructor, input, output, processor), int) => int =
  (selector, count) => {
    switch (selector) {
    | Select(_) => 1 + count
    | Curry(lhs, _) => countSelectors(lhs, 1 + count)
    };
  };

let rec extractSelectors:
  type constructor input output processor.
    (t(constructor, input, output, processor), array(selector), int) => unit =
  (selector, selectors, index) =>
    if (index == (-1)) {
      ();
    } else {
      switch (selector) {
      | Select(selectorFunction) =>
        selectors[index] = castSelector(selectorFunction)
      | Curry(lhs, Select(selectorFunction)) =>
        selectors[index] = castSelector(selectorFunction);
        extractSelectors(lhs, selectors, index - 1);
      };
    };

let create:
  type constructor input output processor.
    (t(constructor, input, output, processor), processor) =>
    (. input) => output =
  (selector, processor) => {
    let selectorLength = countSelectors(selector, 0);
    let selectors = Array.make(selectorLength, castSelector());
    extractSelectors(selector, selectors, selectorLength - 1);
    let callback = castCallback(processor);
    createSelector(selectors, callback);
  };
