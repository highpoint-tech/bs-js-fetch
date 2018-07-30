type url = string;
type result = Js.Promise.t(Js.Json.t);

module Options:
  {
    module Body:
      {
        type t;
        type blob;
        type bufferSource;
        type formData;
        type urlSearchParams;
        let make: string => t;
        let makeWithBlob: blob => t;
        let makeWithBufferSource: bufferSource => t;
        let makeWithFormData: formData => t;
        let makeWithUrlSearchParams: urlSearchParams => t;
      };
    type make;
    let make: (~body: Body.t) => make;
  };
let json: url => result;
let postForm: (url, Options.make) => result;
let postJSON: (url, Options.make) => result;