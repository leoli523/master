
module("luci.jsonrpc", package.seeall)
local uci = require("luci.model.uci").cursor()
require "luci.json"

--local test = {id=uci:get("wireless","wifi0","htmode"), result=uci:get("wireless","wifi1","htmode")}
--local test = {"a":5,"b":"lol","c": [1, 2, 3],"d": {"e": true,"f": false}}
--luci.util.exec("echo "..uci:get("wireless","wifi0","htmode").." >/dev/console")
--luci.util.exec("echo "..uci:get("wireless","wifi1","htmode").." >/dev/console")

--str = luci.json.Encoder(test)
--im_back = luci.json.Decoder(str)


function getJson(config)
	local uci = luci.model.uci.cursor()
	local CC = uci:get_all(config)
	local JSON = require "luci.json"
	local json = JSON.encode(CC)
	return json
end

function print_table(table)
    for v, x in pairs(table) do
        luci.util.exec("echo v:"..v.." >/dev/console")
        if type(x) == "table" then
            print_table(x)
        else
            luci.util.exec("echo v:"..v.."  x:"..tostring(x).." >/dev/console")
        end
    end
end
function readFile(filename)
    local file = io.open(filename,"rb")
    local content = file:read("*a")
    file:close()
    return content
end
--local myTable = {}
--print(readFile("/tmp/000"))
myTable = readFile("/tmp/000")
--[[
local contents1 = ""
local file1 = io.open( "/etc/config/network", "r+" )

if file1 then
    print(file1:read("*a"))
    luci.util.exec("echo file1 >/dev/console")
    -- read all contents of file1 into a string
    local contents1 = file1:read("*a")
    luci.util.exec("echo contents1:"..contents1.." >/dev/console")
    myTable = luci.json.decode(contents1);
    io.close( file1 )
end

local decode = luci.json.decode(myTable)
--print_table(decode)
--local decode = luci.json.decode ('{"mesh":{"mesh_role": "Gateway","mesh_channel": "36"}}')
print_table(decode)
--test = luci.json.encode(decode)
--test:dispatch({echo = {arg1 = "str", arg2 = "abc"}, nice = "[ sos = \"abc\" ]"})
    local file = io.open("/tmp/123", "w")
    --aaa = {["mesh"]={["mesh_role"]= "Gateway",["mesh_channel"]= "36",["mesh_learn_table"]= {{["mac"]= "8a33",["learn_rssi"]= "-70",["link_flags"]= ".."}, {["mac"]= "8a33",["learn_rssi"]= "-70",["link_flags"]= ".."}}}}

	local obj = setmetatable({}, {
		__index = function(self, key)
		return table[key]
		end
	})

]]--
    function json_object_get_idx(obj, element)
        local i = 0
        for _, v in pairs(obj) do
            i = i + 1
            if _ == element then
                return i
            end
        end
    end

    function json_new_object()
        return setmetatable({}, {
            __index = function(self, key)
                return table[key]
            end
        })
    end
    function json_new_array()
        return setmetatable({}, {
            __index = function(self, key)
                return table[key]
            end
        })
    end
    function json_object_add(obj, element, val)
        obj[element]=val
    end

    function json_object_del(obj, element)
        obj[element] = nil
    end

    function json_array_add(arr, obj)
        table.insert(arr, obj) 
    end

    function json_object_mod(obj, element, val)
        obj[element]=val
    end

    obj = json_new_object()
    json_object_add(obj, "mesh_role", "Gateway")
    print(obj.aaa)
    json_object_add(obj, "mesh_channel", "36")
--[[
    mesharr = json_new_array()
    json_new_object(meshobj)
    json_object_add(meshobj, "mac", "8a:dc:96:11:22:33")
    json_object_add(meshobj, "enable", true)
    json_object_add(meshobj, "rate", 18)
    json_object_mod(meshobj, "rssi", "-50")
    json_object_del(meshobj, "rssi")
    --print_table(meshobj)
    json_array_add(mesharr, meshobj)

    json_object_add(obj, "bbbb", "Gateway")
    json_object_add(obj, "mesh_learn_table", mesharr)
]]--

    local file = io.open("/tmp/123", "w")
    if file then
        local contents = luci.json.encode(obj)
        file:write( contents )
        io.close( file )
    end
    test =  setmetatable({}, {
            __index = function(t, key)
                if key == "mesh_role" then
                    luci.util.exec("echo 11111 >/dev/console")
                    return "error"
                else
                    luci.util.exec("echo i2222 >/dev/console")
                    return table[key]
                end
            end
        })
test.aaa = 111
