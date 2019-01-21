type url = string;
type result = Js.Promise.t(Js.Json.t);

module AbortController: {
  type t;
  type signal;
  let signal: t => signal;
  let abort: (t, unit) => unit;
  let make: unit => t;
};

module Options: {
  module Body: {
    type t;
    type blob;
    type bufferSource;
    type formData;
    type urlSearchParams;
    let make: Js.Json.t => t;
    let makeWithBlob: blob => t;
    let makeWithBufferSource: bufferSource => t;
    let makeWithFormData: formData => t;
    let makeWithUrlSearchParams: urlSearchParams => t;
  };
  type make;
  let make: (~body: Body.t=?, ~signal: AbortController.signal=?, unit) => make;
};

let json: (~url: url, ~options: Options.make=?, unit) => result;

let postForm: (~url: url, ~options: Options.make=?, unit) => result;

let postJSON: (~url: url, ~options: Options.make=?, unit) => result;
