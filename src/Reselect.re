[@bs.module "reselect"]
external create1:
  ((. 'state) => 'out1, (. 'out1) => 'output) => (. 'state) => 'output =
  "createSelector";

[@bs.module "reselect"]
external create2:
  ((. 'state) => 'out1, (. 'state) => 'out2, (. 'out1, 'out2) => 'output) =>
  (. 'state) => 'output =
  "createSelector";

[@bs.module "reselect"]
external create3:
  (
    (. 'state) => 'out1,
    (. 'state) => 'out2,
    (. 'state) => 'out3,
    (. 'out1, 'out2, 'out3) => 'output
  ) =>
  (. 'state) => 'output =
  "createSelector";

[@bs.module "reselect"]
external create4:
  (
    (. 'state) => 'out1,
    (. 'state) => 'out2,
    (. 'state) => 'out3,
    (. 'state) => 'out4,
    (. 'out1, 'out2, 'out3, 'out4) => 'output
  ) =>
  (. 'state) => 'output =
  "createSelector";

[@bs.module "reselect"]
external create5:
  (
    (. 'state) => 'out1,
    (. 'state) => 'out2,
    (. 'state) => 'out3,
    (. 'state) => 'out4,
    (. 'state) => 'out5,
    (. 'out1, 'out2, 'out3, 'out3, 'out4, 'out5) => 'output
  ) =>
  (. 'state) => 'output =
  "createSelector";

[@bs.module "reselect"]
external create6:
  (
    (. 'state) => 'out1,
    (. 'state) => 'out2,
    (. 'state) => 'out3,
    (. 'state) => 'out4,
    (. 'state) => 'out5,
    (. 'state) => 'out6,
    (. 'out1, 'out2, 'out3, 'out3, 'out4, 'out5, 'out6) => 'output
  ) =>
  (. 'state) => 'output =
  "createSelector";

[@bs.module "reselect"]
external create7:
  (
    (. 'state) => 'out1,
    (. 'state) => 'out2,
    (. 'state) => 'out3,
    (. 'state) => 'out4,
    (. 'state) => 'out5,
    (. 'state) => 'out6,
    (. 'state) => 'out7,
    (. 'out1, 'out2, 'out3, 'out3, 'out4, 'out5, 'out6, 'out7) => 'output
  ) =>
  (. 'state) => 'output =
  "createSelector";

[@bs.module "reselect"]
external create8:
  (
    (. 'state) => 'out1,
    (. 'state) => 'out2,
    (. 'state) => 'out3,
    (. 'state) => 'out4,
    (. 'state) => 'out5,
    (. 'state) => 'out6,
    (. 'state) => 'out7,
    (. 'state) => 'out8,
    (. 'out1, 'out2, 'out3, 'out3, 'out4, 'out5, 'out6, 'out7, 'out8) =>
    'output
  ) =>
  (. 'state) => 'output =
  "createSelector";

[@bs.module "reselect"]
external create9:
  (
    (. 'state) => 'out1,
    (. 'state) => 'out2,
    (. 'state) => 'out3,
    (. 'state) => 'out4,
    (. 'state) => 'out5,
    (. 'state) => 'out6,
    (. 'state) => 'out7,
    (. 'state) => 'out8,
    (. 'state) => 'out9,
    (. 'out1, 'out2, 'out3, 'out3, 'out4, 'out5, 'out6, 'out7, 'out8, 'out9) =>
    'output
  ) =>
  (. 'state) => 'output =
  "createSelector";
