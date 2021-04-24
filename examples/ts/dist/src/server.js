"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __generator = (this && this.__generator) || function (thisArg, body) {
    var _ = { label: 0, sent: function() { if (t[0] & 1) throw t[1]; return t[1]; }, trys: [], ops: [] }, f, y, t, g;
    return g = { next: verb(0), "throw": verb(1), "return": verb(2) }, typeof Symbol === "function" && (g[Symbol.iterator] = function() { return this; }), g;
    function verb(n) { return function (v) { return step([n, v]); }; }
    function step(op) {
        if (f) throw new TypeError("Generator is already executing.");
        while (_) try {
            if (f = 1, y && (t = op[0] & 2 ? y["return"] : op[0] ? y["throw"] || ((t = y["return"]) && t.call(y), 0) : y.next) && !(t = t.call(y, op[1])).done) return t;
            if (y = 0, t) op = [op[0] & 2, t.value];
            switch (op[0]) {
                case 0: case 1: t = op; break;
                case 4: _.label++; return { value: op[1], done: false };
                case 5: _.label++; y = op[1]; op = [0]; continue;
                case 7: op = _.ops.pop(); _.trys.pop(); continue;
                default:
                    if (!(t = _.trys, t = t.length > 0 && t[t.length - 1]) && (op[0] === 6 || op[0] === 2)) { _ = 0; continue; }
                    if (op[0] === 3 && (!t || (op[1] > t[0] && op[1] < t[3]))) { _.label = op[1]; break; }
                    if (op[0] === 6 && _.label < t[1]) { _.label = t[1]; t = op; break; }
                    if (t && _.label < t[2]) { _.label = t[2]; _.ops.push(op); break; }
                    if (t[2]) _.ops.pop();
                    _.trys.pop(); continue;
            }
            op = body.call(thisArg, _);
        } catch (e) { op = [6, e]; y = 0; } finally { f = t = 0; }
        if (op[0] & 5) throw op[1]; return { value: op[0] ? op[1] : void 0, done: true };
    }
};
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
var grpc_1 = __importDefault(require("grpc"));
var hello_reply_1 = require("./models/hello-reply");
var greeter_grpc_1 = require("./greeter_grpc");
var flatbuffers_1 = require("flatbuffers");
var GreeterServer = /** @class */ (function () {
    function GreeterServer() {
    }
    GreeterServer.prototype.SayHello = function (call, callback) {
        console.log("SayHello " + call.request.name());
        var builder = new flatbuffers_1.flatbuffers.Builder();
        var offset = builder.createString("welcome " + call.request.name());
        var root = hello_reply_1.HelloReply.createHelloReply(builder, offset);
        builder.finish(root);
        callback(null, hello_reply_1.HelloReply.getRootAsHelloReply(new flatbuffers_1.flatbuffers.ByteBuffer(builder.asUint8Array())));
    };
    GreeterServer.prototype.SayManyHellos = function (call) {
        return __awaiter(this, void 0, void 0, function () {
            var name;
            return __generator(this, function (_a) {
                name = call.request.name();
                console.log(call.request.name() + " saying hi in different langagues");
                ['Hi', 'Hallo', 'Ciao'].forEach(function (element) {
                    var builder = new flatbuffers_1.flatbuffers.Builder();
                    var offset = builder.createString(element + " " + name);
                    var root = hello_reply_1.HelloReply.createHelloReply(builder, offset);
                    builder.finish(root);
                    call.write(hello_reply_1.HelloReply.getRootAsHelloReply(new flatbuffers_1.flatbuffers.ByteBuffer(builder.asUint8Array())));
                });
                call.end();
                return [2 /*return*/];
            });
        });
    };
    return GreeterServer;
}());
function serve() {
    var PORT = 3000;
    var server = new grpc_1.default.Server();
    server.addService(greeter_grpc_1.GreeterService, new GreeterServer());
    console.log("Listening on " + PORT);
    server.bind("localhost:" + PORT, grpc_1.default.ServerCredentials.createInsecure());
    server.start();
}
serve();
//# sourceMappingURL=server.js.map