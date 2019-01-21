type url = string;

type result = Js.Promise.t(Js.Json.t);

module AbortController = {
  type t;
  type signal;
  [@bs.get] external signal: t => signal = "";
  [@bs.send] external abort: (t, unit) => unit = "";
  [@bs.new] external make: unit => t = "AbortController";
};

module Options = {
  module Body = {
    type t;
    type blob;
    type bufferSource;
    type formData;
    type urlSearchParams;
    external make: Js.Json.t => t = "%identity";
    external makeWithBlob: blob => t = "%identity";
    external makeWithBufferSource: bufferSource => t = "%identity";
    external makeWithFormData: formData => t = "%identity";
    external makeWithUrlSearchParams: urlSearchParams => t = "%identity";
  };
  [@bs.deriving abstract]
  type make = {
    [@bs.optional]
    body: Body.t,
    [@bs.optional]
    signal: AbortController.signal,
  };
};

[@bs.module "@highpoint/js-fetch"]
external json: (~url: url, ~options: Options.make=?, unit) => result = "";

[@bs.module "@highpoint/js-fetch"]
external postForm: (~url: url, ~options: Options.make=?, unit) => result = "";

[@bs.module "@highpoint/js-fetch"]
external postJSON: (~url: url, ~options: Options.make=?, unit) => result = "";
