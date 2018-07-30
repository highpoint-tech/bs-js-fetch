type url = string; 
type result = Js.Promise.t(Js.Json.t);

module Options = {
  module Body = {
    type t;
    type blob;
    type bufferSource;
    type formData;
    type urlSearchParams;
    external make : string => t = "%identity";
    external makeWithBlob : blob => t = "%identity";
    external makeWithBufferSource : bufferSource => t = "%identity";
    external makeWithFormData : formData => t = "%identity";
    external makeWithUrlSearchParams : urlSearchParams => t = "%identity";
  };
  [@bs.deriving abstract]
  type make = {body: Body.t};
};

[@bs.module "@highpoint/js-fetch"] external json : url => result = "";

[@bs.module "@highpoint/js-fetch"]
external postForm : (url, Options.make) => result = "";

[@bs.module "@highpoint/js-fetch"]
external postJSON : (url, Options.make) => result = "";
